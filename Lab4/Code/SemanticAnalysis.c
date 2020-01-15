#include<stdio.h>
#include"SemanticAnalysis.h"
#include"SymbolTable.h"
#include<stdlib.h>
#include"HelpFunc.h"
extern int mistake;

void Program(Tree *root){
    ExtDefList(root->child[0]);
}

void ExtDefList(Tree *root){
    if(root==NULL)
        return ;
    ExtDef(root->child[0]);
    ExtDefList(root->child[1]);
}

void ExtDef(Tree *root){
    const Type type=Specifier(root->child[0]);
    if(strcmp(root->child[1]->name,"ExtDecList")==0){
        ExtDecList(root->child[1],type);
    }
    else if(strcmp(root->child[1]->name,"SEMI")==0){
        ;
    }
    else if(strcmp(root->child[1]->name,"FunDec")==0){
        FunDec(root->child[1],type);
        Compst(root->child[2],type);
    }
}

Type Specifier(Tree *root){
    if(strcmp(root->child[0]->name,"TYPE")==0){
        Type type=(Type)malloc(sizeof(struct Type_));
        type->kind=BASIC;
        if(strcmp(root->child[0]->text,"int")==0){
            type->u.basic=TYPE_INT;
        }
        else if(strcmp(root->child[0]->text,"float")==0)
            type->u.basic=TYPE_FLOAT;
        return type;
    }
    else{
        return StructSpecifier(root->child[0]);
    }
}

Type StructSpecifier(Tree *root){
    HashNode node=(HashNode)malloc(sizeof(struct HashNode_));
    Type type=NULL;
    char *structname=(char*) malloc(sizeof(root->child[1]->child[0]->text)+2);
    if(root->childnum==2){
        strcpy(structname,root->child[1]->child[0]->text);
        const HashNode checknode=check(structname,0);
        if(checknode==NULL){
            //Error,未定义的结构体,或者结构体的声明？
            type=(Type)malloc(sizeof(struct Type_));
            type->kind=ERROR;
            mistake++;
            printf("Error Type 17 at Line %d: Undefined structure \"%s\".\n",root->child[1]->line,structname);
        }
        else if(checknode->val->kind!=STRUCTURE){
            //Error，未定义的结构体,或者结构体的声明？
            type=(Type)malloc(sizeof(struct Type_));
            type->kind=ERROR;
            mistake++;
            printf("Error Type 17 at Line %d: Undefined structure\"%s\".\n",root->child[1]->line,structname);
        }
        else type=mycopy_type(checknode->val);
    }
    else{
        if(root->child[1]!=NULL){
            strcpy(structname,root->child[1]->child[0]->text);
        }
        //如果=NULL怎么办？
        const HashNode checknode=check(structname,0);
        if(checknode!=NULL){
            ;//Error，重定义的结构体或变量,error type 16
            mistake++;
            printf("Error Type 16 at Line %d: Refined structure \"%s\".\n",root->child[1]->line,structname);
        }
        else{
            strcpy(node->name,structname);
            type=(Type)malloc(sizeof(struct Type_));
            type->kind=STRUCTURE;
            //temp是临时变量，用来判断struct中的域是否重复
            FieldList temp=(FieldList)malloc(sizeof(struct FieldList_));
            temp->next=NULL;
            DefList_in_Struct(root->child[3],temp);
            type->u.structure=temp->next;
            free(temp);
            //其中temp是FieldList链表的头结点；
            node->val=mycopy_type(type);
            node->next=NULL;
            insertnode(node);
        }
    }
    return type;
}

/*Definition about struct*/

void DefList_in_Struct(Tree *root,FieldList head)//DefList_in_Struct中的域还没有判断是否重复，
//那就在StructSpecifier中判断是否重复
{
    if(root!=NULL){
        FieldList a=Def_in_Struct(root->child[0]);
        //a中不一定只有一个节点，因为int i,j,k这种情况的话就有很多个节点;
        FieldList a_pointer=a;
        while(a_pointer!=NULL){ 
            FieldList cur=head->next;
            while(cur!=NULL){
                if(strcmp(cur->name,a_pointer->name)==0){//域重名
                //error15,域重名
                    mistake++;
                    printf("Error Type 15 at Line %d: Refined field \"%s\".\n",root->child[0]->line,a_pointer->name);
                    break;
                }
                cur=cur->next;
            }
            a_pointer=a_pointer->next;
        }
        FieldList tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=a;
        DefList_in_Struct(root->child[1],head);
        return ;
    } 
}
FieldList Def_in_Struct(Tree *root)
{
    Type dec_type=Specifier(root->child[0]);
    FieldList ans=DecList_in_Struct(root->child[1],dec_type);
    return ans;
}
FieldList DecList_in_Struct(Tree*root,Type dec_type)
{
    if(root->childnum==1){
        return Dec_in_Struct(root->child[0],dec_type);   
    }
    else{
        FieldList ans=Dec_in_Struct(root->child[0],dec_type);
        ans->next=DecList_in_Struct(root->child[2],dec_type);
        return ans;
    }
}
FieldList Dec_in_Struct(Tree *root,Type dec_type)
{
    FieldList ans=(FieldList)malloc(sizeof(struct FieldList_)); 
    HashNode temp=VarDec(root->child[0],dec_type);
    ans->type=temp->val;
    strcpy(ans->name,temp->name);
    free(temp);
    //把temp的type赋给ans的type,然后复制name,之后delete掉temp;;
    if(root->childnum==3)
    {
        //error 15结构体中的变量初始化
        mistake++;
        printf("Error Type 15 at Line %d:  wrongly defined structure\"%s\".\n",root->child[0]->line,ans->name);
    }
    return ans;
}

/*Definition in Function*/
void FunDec(Tree *root,const Type return_type){
    FuncList func=(FuncList)malloc(sizeof(struct FuncList_));
    strcpy(func->name,root->child[0]->text);
    func->type=mycopy_type(return_type);
    if(root->childnum==4){
        func->next=VarList(root->child[2]);
    }
    else{
        func->next=NULL;
    }
    HashNode checknode=check(func->name,1);
    if(checknode!=NULL){
        mistake++;
        printf("Error type 4 at line %d: Redefined function \"%s\".\n",root->line,func->name);
        ;//Error,重定义
    }
    else{
        HashNode node=(HashNode)malloc(sizeof(struct HashNode_));
        strcpy(node->name,func->name);
        node->val=(Type)malloc(sizeof(struct Type_));
        node->val->kind=FUNCTION;
        node->val->u.myfunc=func;
        node->next=NULL;
        insertnode(node);
    }
}
FuncList VarList(Tree *root){
    FuncList oneParam=ParamDec(root->child[0]);
    HashNode checknode=check(oneParam->name,0);
    if(checknode!=NULL){
        mistake++;
        printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",root->line,oneParam->name);
        ;//Error,重定义
    }
    else{
        HashNode node=(HashNode)malloc(sizeof(struct HashNode_));
        strcpy(node->name,oneParam->name);
        node->val=mycopy_type(oneParam->type);
        node->next=NULL;
        insertnode(node);
    }
    if(root->childnum>1){
        oneParam->next=VarList(root->child[2]);
    }
    return oneParam;
}
FuncList ParamDec(Tree *root){
    Type type=Specifier(root->child[0]);
    //char name[32];
    /*HashNode vardec=VarDec(root->child[1],type);
    FuncList func=(FuncList)malloc(sizeof(struct FuncList_));
    strcpy(func->name,vardec->name);
    func->type=vardec->val;
    func->next=NULL;
    return func;*/
    return (FuncList)VarDec(root->child[1],type);
}

HashNode VarDec(Tree *root,Type type)
{
    if(strcmp(root->child[0]->name,"ID")==0){
        HashNode ans=(HashNode)malloc(sizeof(struct HashNode_));
        strcpy(ans->name,root->child[0]->text);
        ans->val=mycopy_type(type);
        ans->next=NULL;
        return ans;
    }
    else{
        Type ans=(Type)malloc(sizeof(struct Type_));
        ans->kind=ARRAY;
        ans->u.array.size=string_to_int(root->child[2]->text);
        HashNode res=VarDec(root->child[0],type);
        ans->u.array.elem=res->val;
        res->val=ans;
        return res;
    }
}

void ExtDecList(Tree *root,Type type){
    HashNode node=VarDec(root->child[0],type);
    HashNode checknode=check(node->name,0);
    
    if(checknode!=NULL){
        mistake++;
        printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",root->line,node->name);
        ;//Error，重定义
    }
    else{
        /*strcpy(node->name,name);
        node->val=mycopy_type(mytype);
        free(mytype);
        node->next=NULL;*/
        //printf("haaha\n");
        insertnode(node);
    }
    if(root->childnum>1){
        ExtDecList(root->child[2],type);
    }
}

/*Expression*/
void Compst(Tree *root,Type return_type)
{
    DefList_in_Function(root->child[1]);
    StmtList(root->child[2],return_type);
}
void StmtList(Tree *root,Type return_type)
{
    if(root!=NULL)
    {
        Stmt(root->child[0],return_type);
        StmtList(root->child[1],return_type);
    }
}
void Stmt(Tree *root,Type return_type)
{
    if(strcmp(root->child[0]->name,"Exp")==0)
    {
        Exp(root->child[0]);
    }
    else if(strcmp(root->child[0]->name,"CompSt")==0)
    {
        Compst(root->child[0],return_type);
    }
    else if(strcmp(root->child[0]->name,"RETURN")==0)
    {
        Type my_ret=Exp(root->child[1]);
        if(isTypeEqual(my_ret,return_type)==0)
        {
            mistake++;
            printf("Error type 8 at line %d: Type mismatched for return.\n",root->child[0]->line);
        }
    }
    else if(strcmp(root->child[0]->name,"WHILE")==0)
    {
        Type mytype=Exp(root->child[2]);
        if(!(mytype->kind==BASIC&&mytype->u.basic==TYPE_INT))
        {
            //error,以外的error，if，while内的exp类型不是int
            mistake++;
            printf("Error type 7 at line %d: the expr's type in while( ) is not an integer.\n",root->line);
        }
        Stmt(root->child[4],return_type);
    }
   else if(root->childnum==5)
   {
        Type mytype=Exp(root->child[2]);
        if(!(mytype->kind==BASIC&&mytype->u.basic==TYPE_INT))
        {
            //error,以外的error，if，while内的exp类型不是int
            mistake++;
            printf("Error type 7 at line %d: the expr's type in if( ) is not an integer.\n",root->line);
        }
        Stmt(root->child[4],return_type);
   }
   else
   {
        Type mytype=Exp(root->child[2]);
        if(!(mytype->kind==BASIC&&mytype->u.basic==TYPE_INT))
        {
            //error,以外的error，if，while内的exp类型不是int
            mistake++;
            printf("Error type 7 at line %d: the expr's type in if( ) is not an integer.\n",root->line);
        }
        Stmt(root->child[4],return_type);
        Stmt(root->child[6],return_type);
   }
}
void DefList_in_Function(Tree *root){
    if(root!=NULL){      
        Def_in_Function(root->child[0]);
        //a中不一定只有一个节点，因为int i,j,k这种情况的话就有很多个节点;
        DefList_in_Function(root->child[1]);
        return ;
    } 
}
void Def_in_Function(Tree *root){
        Type dec_type=Specifier(root->child[0]);
        DecList_in_Function(root->child[1],dec_type);
}
void DecList_in_Function(Tree*root,Type dec_type){
    if(root->childnum==1){
         Dec_in_Function(root->child[0],dec_type);
    }
    else{
        Dec_in_Function(root->child[0],dec_type);
        DecList_in_Function(root->child[2],dec_type);
    }
}
void Dec_in_Function(Tree *root,Type dec_type){
//在该函数中已经将变量插入到符号表中，并且错误类型判断也已完成
    if(root->childnum==1){
        HashNode ans=VarDec(root->child[0],dec_type);
        HashNode judge=check(ans->name,0);
        if(judge==NULL){//无重复，可以插入
            insertnode(ans);
        }
        else{
            mistake++;
            printf("Error Type 3 at Line %d: Refined variable \"%s\".\n",root->child[0]->line,ans->name);
        }
    }
    else{
        HashNode ans=VarDec(root->child[0],dec_type);
        HashNode judge=check(ans->name,0);
        Type myret=Exp(root->child[2]);
        if(isTypeEqual(myret,ans->val)==0){
            mistake++;
            printf("Error Type 5 at Line %d: Type mismatched for assignment.\n",root->child[0]->line);
        }
        if(judge==NULL){//无重复，可以插入
            insertnode(ans);
        }
        else{
            mistake++;
            printf("Error Type 3 at Line %d: Refined variable \"%s\".\n",root->child[0]->line,ans->name);
        }
    }
}

Type Exp(Tree *root){
    if(root->childnum==1){
        if(strcmp(root->child[0]->name,"ID")==0){
            return Exp_ID(root);
        }
        else if(strcmp(root->child[0]->name,"FLOAT")==0){
            return Exp_FLOAT(root->child[0]);
        }
        else if(strcmp(root->child[0]->name,"INT")==0){
            return Exp_INT(root->child[0]);
        }
    }
    else if(root->childnum==2){
        if(strcmp(root->child[0]->name,"MINUS")==0){
            return Exp_MINUS(root);
        }
        else if(strcmp(root->child[0]->name,"NOT")==0){
            return Exp_NOT(root);
        }
    }
    else if(root->childnum==3){
        if(strcmp(root->child[0]->name,"LP")==0){
            return Exp_LP_RP(root->child[1]);
        }
        else if(strcmp(root->child[0]->name,"ID")==0){
            return Exp_FuncTrans(root);
        }
        else if(strcmp(root->child[0]->name,"Exp")==0){
            if(strcmp(root->child[1]->name,"ASSIGNOP")==0){
                return Exp_ASSIGNOP(root);
            }
            else if(strcmp(root->child[1]->name,"AND")==0||strcmp(root->child[1]->name,"OR")==0){
                return Exp_AND_OR(root);
            }
            else if(strcmp(root->child[1]->name,"DOT")==0){
                return Exp_Struct(root);
            }
            else{
                return Exp_RELOP_and_MATH(root);
            }
        }
    }
    else{
        if(strcmp(root->child[0]->name,"ID")==0){
            return Exp_FuncTrans(root);
        }  
        else{
            return Exp_Array(root);
        }
    }
}
Type Exp_ASSIGNOP(Tree *root){
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    Type type=Exp(root->child[0]);
    
    Type res = (isTypeEqual(type,Exp(root->child[2])))?type:errortype;
    if(res->kind==ERROR){
        mistake++;
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",root->line);
    }
    else{
        if(root->child[0]->expr==left){
            root->expr=left;
            return res;
        }
        else{
            mistake++;
            printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n",root->line);
            return errortype;
        }
    }
}
Type Exp_AND_OR(Tree *root){
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    Type type=Exp(root->child[0]);
    Type res = (isTypeEqual(type,Exp(root->child[2]))
                &&
                type->kind==BASIC
                &&
                type->u.basic==TYPE_INT)?type:errortype;
    if(res->kind==ERROR){
        mistake++;
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",root->line);
    }
    return res;
}
Type Exp_RELOP_and_MATH(Tree *root){
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    Type type=Exp(root->child[0]);
    Type res;
    if(strcmp(root->child[1]->name,"RELOP")==0){
        Type res_INT=(Type)malloc(sizeof(struct Type_));
        res_INT->kind=BASIC;
        res_INT->u.basic=TYPE_INT;
        res = (isTypeEqual(type,Exp(root->child[2]))
                &&
                type->kind==BASIC)?res_INT:errortype;
    }
    else{
        res = (isTypeEqual(type,Exp(root->child[2]))
                &&type->kind==BASIC)?type:errortype;
    }
    if(res->kind==ERROR){
        mistake++;
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",root->line);
    }
    return res;
}
Type Exp_LP_RP(Tree *root){
    return Exp(root);
}
Type Exp_MINUS(Tree *root){
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    Type type=Exp(root->child[1]);
    Type res = (type->kind==BASIC)?type:errortype;
    if(res->kind==ERROR){
        mistake++;
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",root->line);
    }
    return res;
}
Type Exp_NOT(Tree *root){
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    Type type=Exp(root->child[1]);
    Type res = (type->kind==BASIC
                &&
                type->u.basic==TYPE_INT)?type:errortype;
    if(res->kind==ERROR){
        mistake++;
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",root->line);
    }
    return res;
}
Type Exp_FuncTrans(Tree *root){//函数调用
    char funcname[32];
    strcpy(funcname,root->child[0]->text);
    HashNode checknode=check(funcname,1);
    HashNode checknode_var=check(funcname,0);
    Type errortype=(Type)malloc(sizeof(struct Type_));
    errortype->kind=ERROR;
    if(checknode==NULL){
        mistake++;
        if(checknode_var!=NULL){
            mistake++;
            printf("Error type 11 at Line %d: \"%s\" is not a function.\n",root->line,funcname);
        }
        else{
            mistake++;
            printf("Error type 2 at Line %d: Undefined function \"%s\".\n",root->line,root->child[0]->text);
        }
        return errortype;
    }
    else{
        Type type=mycopy_type(checknode->val->u.myfunc->type);//函数的返回类型
        if(root->childnum==3){
            return type;
        }
        else{
            //直接把参数传给Args函数
            if(Args(root->child[2],checknode->val->u.myfunc->next)){
                //调用符合函数的定义
                return type;
            }
            else{
                mistake++;
                printf("Error type 9 at Line %d: Function \"%s\" is not applicable for arguments.\n",root->line,checknode->name);
                return errortype;
            }
        }
    }
}
Type Exp_Array(Tree *root){//数组访问
    Type temp=Exp(root->child[0]);
    Type number=Exp(root->child[2]);
    Type ans=NULL;
    if(temp->kind!=ARRAY){//非数组型变量，无法使用数组访问操作符
        mistake++;
        printf("Error Type 10 at Line %d: Not an array before [  ].\n",root->child[0]->line);
        ans=(Type)malloc(sizeof(struct Type_));
        ans->kind=ERROR;
        return ans;
    }
    else{
        ans=temp->u.array.elem;
        temp->u.array.elem=NULL;
        free(temp);
    }
    if(number->kind!=BASIC||number->u.basic!=TYPE_INT){
        mistake++;
        printf("Error Type 12 at Line %d: Not an integer between [ and ].\n",root->child[0]->line);
        ans=(Type)malloc(sizeof(struct Type_));
        ans->kind=ERROR;
        return ans;
    }
    root->expr=left;
    return ans;
}
Type Exp_Struct(Tree *root){//结构体访问
    Type type=Exp(root->child[0]);
    Type errortype=(Type)malloc(sizeof(struct Type_));
        errortype->kind=ERROR;
    if(type->kind!=STRUCTURE){
        mistake++;
        printf("Error type 13 at Line %d: Illegal use of \".\".\n",root->line);
        return errortype;
    }
    else{
        char fieldname[32];
        strcpy(fieldname,root->child[2]->text);
        FieldList cur=type->u.structure;
        while(cur!=NULL){
            if(strcmp(cur->name,fieldname)==0)
                break;
            cur=cur->next;
        }
        if(cur==NULL){
            mistake++;
            printf("Error type 14 at Line %d: Non-existent field \"%s\".\n",root->line,fieldname);
            return errortype;
        }
        else{
            root->expr=left;
            return cur->type;
        }
    }
}
Type Exp_ID(Tree *root){
    HashNode checknode=check(root->child[0]->text,0);
    HashNode checknode1=check(root->child[0]->text,1);
    if(checknode==NULL&&checknode1==NULL){
        Type errortype=(Type)malloc(sizeof(struct Type_));
        errortype->kind=ERROR;
        mistake++;
        printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",root->line,root->child[0]->text);
        return errortype;
    }
    else{
        Type type;
        if(checknode==NULL){
            type=mycopy_type(checknode1->val);
        }
        else{
            type=mycopy_type(checknode->val);
            root->expr=left;
        } 
        return type;
    }
}
Type Exp_INT(Tree *root){
    Type type=(Type)malloc(sizeof(struct Type_));
    type->kind=BASIC;
    type->u.basic=TYPE_INT;
    return type;
}
Type Exp_FLOAT(Tree *root){
    Type type=(Type)malloc(sizeof(struct Type_));
    type->kind=BASIC;
    type->u.basic=TYPE_FLOAT;
    return type;
}
int Args(Tree *root,FuncList func){
    while(root->childnum>1){
        if(func==NULL)//调用的参数个数大于函数定义的参数个数
            return 0;
        if(!isTypeEqual(Exp(root->child[0]),func->type)){//参数类型不匹配
            return 0;
        }
        root=root->child[2];
        func=func->next;
    }
    if(func==NULL){//还有一个调用参数，但此时函数定义的参数已经买没有了
        return 0;
    }
    if(!isTypeEqual(Exp(root->child[0]),func->type)){//参数类型不匹配
        return 0;
    }
    if(func->next!=NULL){//调用的参数个数少于函数定义的参数个数
        return 0;
    }
    return 1;
}