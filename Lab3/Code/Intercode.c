#include<stdio.h>
#include"SemanticAnalysis.h"
#include"SymbolTable.h"
#include<stdlib.h>
#include"HelpFunc.h"
#include"Intercode.h"
extern int yylineno;
extern int mistake;
int state=0;
int state1=0;
int state2=0;
extern FILE *fp;
int calculate_size(Type temp)
{
    if(temp->kind==BASIC)
    {
        return 4;
    }
    else if(temp->kind==ARRAY)
    {
        return temp->u.array.size*calculate_size(temp->u.array.elem);
    }
    else if(temp->kind==STRUCTURE)
    {
        int size=0;
        FieldList list=temp->u.structure;
        while(list!=NULL)
        {
            size+=calculate_size(list->type);
            list=list->next;
        }
        return size;
    }
}

/*void printOperand(Operand ope){
    if(ope->kind==CONSTANT||ope->kind==VAR_CONS){
        printf("#%d",ope->u.var_no);
    }
    else if(ope->kind==TEMP_ADDR||ope->kind==VAR_ADDR){
        
        printf("&%s",ope->u.value);
    }
    else if(ope->kind==MYSTAR){
        printf("*%s",ope->u.value);
    }
    else{
        printf("%s",ope->u.value);
    }
}
void printIR(InterCode head){
    while(head!=NULL){
        if(head->kind==W_LABEL){
            printf("LABEL %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_FUNCTION){
            printf("FUNCTION %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_ASSIGN){
            printOperand(head->u.Assign.left);
            printf(" := ");
            printOperand(head->u.Assign.right);
            printf("\n");
        }
        else if(head->kind==W_ADD||head->kind==W_SUB||head->kind==W_MUL||head->kind==W_DIV){
            printOperand(head->u.Double.result);
            printf(" := ");
            printOperand(head->u.Double.op1);
            if(head->kind==W_ADD){
                printf(" + ");
            }
            else if(head->kind==W_SUB){
                printf(" - ");
            }
            else if(head->kind==W_MUL){
                printf(" * ");
            }
            else if(head->kind==W_DIV){
                printf(" / ");
            }
            printOperand(head->u.Double.op2);
            printf("\n");
        }
        else if(head->kind==W_GOTO){
            printf("GOTO ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_IFGOTO){
            printf("IF ");
            printOperand(head->u.Three.x);
            printf(" %s ",head->u.Three.relop);
            printOperand(head->u.Three.y);
            printf(" GOTO ");
            printOperand(head->u.Three.label);
            printf("\n");
        }
        else if(head->kind==W_RETURN){
            printf("RETURN ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_DEC){
            printf("DEC ");
            printOperand(head->u.Dec.op);
            printf(" %d\n",head->u.Dec.size);
        }
        else if(head->kind==W_ARG){
            printf("ARG ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_CALL){
            printOperand(head->u.Assign.left);
            printf(" := CALL ");
            printOperand(head->u.Assign.right);
            printf("\n");
        }
        else if(head->kind==W_PARAM){
            printf("PARAM ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_READ){
            printf("READ ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_WRITE){
            printf("WRITE ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        head=head->next;
    }
}*/

void printOperand(Operand ope){
    if(ope->kind==CONSTANT||ope->kind==VAR_CONS){
        fprintf(fp,"#%d",ope->u.var_no);
    }
    else if(ope->kind==TEMP_ADDR||ope->kind==VAR_ADDR){
        fprintf(fp,"&%s",ope->u.value);
    }
    else if(ope->kind==MYSTAR){
        fprintf(fp,"*%s",ope->u.value);
    }
    else{
        fprintf(fp,"%s",ope->u.value);
    }
}
void printIR(InterCode head){
    while(head!=NULL){
        if(head->kind==W_LABEL){
            fprintf(fp,"LABEL %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_FUNCTION){
            fprintf(fp,"FUNCTION %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_ASSIGN){
            printOperand(head->u.Assign.left);
            fprintf(fp," := ");
            printOperand(head->u.Assign.right);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_ADD||head->kind==W_SUB||head->kind==W_MUL||head->kind==W_DIV){
            printOperand(head->u.Double.result);
            fprintf(fp," := ");
            printOperand(head->u.Double.op1);
            if(head->kind==W_ADD){
                fprintf(fp," + ");
            }
            else if(head->kind==W_SUB){
                fprintf(fp," - ");
            }
            else if(head->kind==W_MUL){
                fprintf(fp," * ");
            }
            else if(head->kind==W_DIV){
                fprintf(fp," / ");
            }
            printOperand(head->u.Double.op2);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_GOTO){
            fprintf(fp,"GOTO ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_IFGOTO){
            fprintf(fp,"IF ");
            printOperand(head->u.Three.x);
            fprintf(fp," %s ",head->u.Three.relop);
            printOperand(head->u.Three.y);
            fprintf(fp," GOTO ");
            printOperand(head->u.Three.label);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_RETURN){
            fprintf(fp,"RETURN ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_DEC){
            fprintf(fp,"DEC ");
            printOperand(head->u.Dec.op);
            fprintf(fp," %d\n",head->u.Dec.size);
        }
        else if(head->kind==W_ARG){
            fprintf(fp,"ARG ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_CALL){
            printOperand(head->u.Assign.left);
            fprintf(fp," := CALL ");
            printOperand(head->u.Assign.right);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_PARAM){
            fprintf(fp,"PARAM ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_READ){
            fprintf(fp,"READ ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        else if(head->kind==W_WRITE){
            fprintf(fp,"WRITE ");
            printOperand(head->u.Single.op);
            fprintf(fp,"\n");
        }
        head=head->next;
    }
}
void Inter_insert(InterCode a)
{
    if(code_head==NULL)
    {
        code_head=a;
        code_tail=a;
        code_head->next=NULL;
        code_head->pre=NULL;
    }
    else
    {
        code_tail->next=a;
        a->pre=code_tail;
        a->next=NULL;
        code_tail=code_tail->next;
    }
}

Operand new_temp()
{
    Temp_Num++;
    Operand ans=(Operand)malloc(sizeof(struct Operand_));
    ans->kind=TEMP_VAR;
    strcpy(ans->u.value,"ttt");
    char str[32];
    int i=0;
    int temp=Temp_Num;
    while(temp>0)
    {
        int a=temp%10;
        str[i++]=a+'0';
        temp=temp/10;
    }
    str[i]='\0';
    //printf("%s\n",str);
    int m=0,n=i-1;
    while(m<n)
    {
        int hhh=str[m];
        str[m]=str[n];
        str[n]=hhh;
        m++,n--;
    }
    strcat(ans->u.value,str);
    return ans;
}

Operand new_label()
{
    Label_Num++;
    Operand ans=(Operand)malloc(sizeof(struct Operand_));
    ans->kind=LABEL;
    strcpy(ans->u.value,"label");
    char str[32];
    int i=0;
    int temp=Label_Num;
    while(temp>0)
    {
        int a=temp%10;
        str[i++]=a+'0';
        temp=temp/10;
    }
    str[i]='\0';
    int m=0,n=i-1;
    while(m<n)
    {
        int hhh=str[m];
        str[m]=str[n];
        str[n]=hhh;
        m++,n--;
    }
    strcat(ans->u.value,str);
    return ans;
}

Operand create_label(int x)
{
    Operand ans=(Operand)malloc(sizeof(struct Operand_));
    ans->kind=LABEL;
    strcpy(ans->u.value,"label");
    char str[32];
    int i=0;
    int temp=x;
    while(temp>0)
    {
        int a=temp%10;
        str[i++]=a+'0';
        temp=temp/10;
    }
    str[i]='\0';
    int m=0,n=i-1;
    while(m<n)
    {
        int hhh=str[m];
        str[m]=str[n];
        str[n]=hhh;
        m++,n--;
    }
    strcat(ans->u.value,str);
    return ans;
}

void Trans_Program(Tree *root){
    Trans_ExtDefList(root->child[0]);
}

void Trans_ExtDefList(Tree *root){
    if(root==NULL)
        return ;
    Trans_ExtDef(root->child[0]);
    Trans_ExtDefList(root->child[1]);
}

void Trans_ExtDef(Tree *root){
    /*if(strcmp(root->child[1]->name,"ExtDecList")==0){
        //Trans_ExtDecList(root->child[1]);
    }
    else */
    if(strcmp(root->child[1]->name,"FunDec")==0){
        Trans_FunDec(root->child[1]);
        Trans_Compst(root->child[2]);
    }
}

/*Definition in Function*/
void Trans_FunDec(Tree *root){
    /*TODO 输出FUNCTION name*/
    InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
    Operand temp=(Operand)malloc(sizeof(struct Operand_));
    temp->kind=VARIABLE;
    strcpy(temp->u.value,root->child[0]->text);
    code2->u.Single.op=temp;
    code2->kind=W_FUNCTION;
    Inter_insert(code2);
    if(root->childnum==4){
        Trans_VarList(root->child[2]);
    }
}

void Trans_VarList(Tree *root){
    Trans_ParamDec(root->child[0]);
    if(root->childnum>1){
        Trans_VarList(root->child[2]);
    }
    return ;
}
void Trans_ParamDec(Tree *root){
    Trans_VarDec_Func(root->child[1]);
    return ;
}

void Trans_VarDec_Func(Tree *root)
{
    if(strcmp(root->child[0]->name,"ID")==0){
    HashNode checknode=check(root->child[0]->text,0);
    InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
    Operand temp=(Operand)malloc(sizeof(struct Operand_));
    temp->kind=VARIABLE;
    strcpy(temp->u.value,root->child[0]->text);
    code2->u.Single.op=temp;
    code2->kind=W_PARAM;
    Inter_insert(code2);
    if(checknode->val->kind==STRUCTURE)
    {
        char*name=(char*)malloc(32*sizeof(char));
        strcpy(name,root->child[0]->text);
        insert_param_structure(name);
        }
    }
    else{
        mistake++;
        printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type\n");
    }
}

void Trans_VarDec_Local(Tree *root)
{
    if(strcmp(root->child[0]->name,"ID")==0){
       //查符号表，如果是数组或结构体，要输出Dec
       HashNode checknode=check(root->child[0]->text,0);
       if(checknode->val->kind==STRUCTURE)
       {
           int size=0;
           size=calculate_size(checknode->val);
            InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
            Operand temp=(Operand)malloc(sizeof(struct Operand_));
            temp->kind=VARIABLE;
            strcpy(temp->u.value,root->child[0]->text);
            code2->u.Dec.op=temp;
            code2->u.Dec.size=size;
            code2->kind=W_DEC;
            Inter_insert(code2);
       }
       else if(checknode->val->kind==ARRAY)
       {
           if(checknode->val->u.array.elem->kind==ARRAY)//multi-array
           {
               mistake++;
               printf("Cannot translate: Code contains variables of multi-dimensional array type for parameters of array type\n");
           }
           else
           {
            int size=0;
           size=calculate_size(checknode->val);
            InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
            Operand temp=(Operand)malloc(sizeof(struct Operand_));
            temp->kind=VARIABLE;
            strcpy(temp->u.value,root->child[0]->text);
            code2->u.Dec.op=temp;
            code2->u.Dec.size=size;
            code2->kind=W_DEC;
            Inter_insert(code2);
           }
       }
    }
    else{
        Trans_VarDec_Local(root->child[0]);
    }
}

/*Expression*/
void Trans_Compst(Tree *root)
{
    Trans_DefList_in_Function(root->child[1]);
    Trans_StmtList(root->child[2]);
}
void Trans_StmtList(Tree *root)
{
    if(root!=NULL)
    {
        Trans_Stmt(root->child[0]);
        Trans_StmtList(root->child[1]);
    }
}
void Trans_Stmt(Tree *root)
{
    if(strcmp(root->child[0]->name,"Exp")==0)
    {
        Operand place=(Operand)malloc(sizeof(struct Operand_));
        place->kind=NONE;
        Trans_Exp(root->child[0],place);
    }
    else if(strcmp(root->child[0]->name,"CompSt")==0)
    {
        Trans_Compst(root->child[0]);
    }
    else if(strcmp(root->child[0]->name,"RETURN")==0)
    {
        Operand t1=new_temp();
        Trans_Exp(root->child[1],t1);
        //code1
        InterCode ans=(InterCode)malloc(sizeof(struct InterCode_));
        ans->kind=W_RETURN;
        ans->u.Single.op=t1;
        Inter_insert(ans);
        //code2
    }
    else if(strcmp(root->child[0]->name,"WHILE")==0)
    {
        Operand label1=new_label();
        int x1=Label_Num;
        Operand label2=new_label();
        int x2=Label_Num;
        Operand label3=new_label();
        int x3=Label_Num;
        InterCode ans1=(InterCode)malloc(sizeof(struct InterCode_));
        ans1->kind=W_LABEL;
        ans1->u.Single.op=label1;
        Inter_insert(ans1);
        //label1
        state=1;
        Trans_Cond(root->child[2],x2,x3);
        state=0;
        //code1
        InterCode ans2=(InterCode)malloc(sizeof(struct InterCode_));
        ans2->kind=W_LABEL;
        ans2->u.Single.op=label2;
        Inter_insert(ans2);
        //label2
        state1++;
        //state=2;
        Trans_Stmt(root->child[4]);
        //state=0;
        state1--;
        //code2
        InterCode temp=(InterCode)malloc(sizeof(struct InterCode_));
        temp->kind=W_GOTO;
        Operand wxy=create_label(x1);
        temp->u.Single.op=wxy;
        Inter_insert(temp);
        //goto label1
        InterCode ans3=(InterCode)malloc(sizeof(struct InterCode_));
        ans3->kind=W_LABEL;
        ans3->u.Single.op=label3;
        Inter_insert(ans3);
        //label3
        return ;
    }
   else if(root->childnum==5)//if-then
   {
        Operand label1=new_label();
        int x1=Label_Num;
        Operand label2=new_label();
        int x2=Label_Num;
        Trans_Cond(root->child[2],x1,x2);
        //code1
        InterCode ans1=(InterCode)malloc(sizeof(struct InterCode_));
        ans1->kind=W_LABEL;
        ans1->u.Single.op=label1;
        Inter_insert(ans1);
        //label1
        state2++;
        Trans_Stmt(root->child[4]);
        state2--;
        //code2
        InterCode ans2=(InterCode)malloc(sizeof(struct InterCode_));
        ans2->kind=W_LABEL;
        ans2->u.Single.op=label2;
        Inter_insert(ans2);
        //label2
        return ;
   }
   else//if-then-else
   {
        Operand label1=new_label();
        int x1=Label_Num;
        Operand label2=new_label();
        int x2=Label_Num;
        Operand label3=new_label();
        int x3=Label_Num;
        Trans_Cond(root->child[2],x1,x2);
        //code1
        InterCode ans1=(InterCode)malloc(sizeof(struct InterCode_));
        ans1->kind=W_LABEL;
        ans1->u.Single.op=label1;
        Inter_insert(ans1);
        //label1
        state2++;
        Trans_Stmt(root->child[4]);
        state2--;
        //code2
        InterCode temp=(InterCode)malloc(sizeof(struct InterCode_));
        temp->kind=W_GOTO;
        Operand wxy=create_label(x3);
        temp->u.Single.op=wxy;
        Inter_insert(temp);
        //goto label3
        InterCode ans2=(InterCode)malloc(sizeof(struct InterCode_));
        ans2->kind=W_LABEL;
        ans2->u.Single.op=label2;
        Inter_insert(ans2);
        //label2
        state2++;
        Trans_Stmt(root->child[6]);
        state2--;
        //code3
        InterCode ans3=(InterCode)malloc(sizeof(struct InterCode_));
        ans3->kind=W_LABEL;
        ans3->u.Single.op=label3;
        Inter_insert(ans3);
        //label3
        return ;
   }
}
void Trans_DefList_in_Function(Tree *root){
    if(root!=NULL){      
        Trans_Def_in_Function(root->child[0]);
        //a中不一定只有一个节点，因为int i,j,k这种情况的话就有很多个节点;
        Trans_DefList_in_Function(root->child[1]);
        return ;
    } 
}
void Trans_Def_in_Function(Tree *root){
    Trans_DecList_in_Function(root->child[1]);
}
void Trans_DecList_in_Function(Tree*root){
    if(root->childnum==1){
         Trans_Dec_in_Function(root->child[0]);
    }
    else{
        Trans_Dec_in_Function(root->child[0]);
        Trans_DecList_in_Function(root->child[2]);
    }
}
void Trans_Dec_in_Function(Tree *root){
    if(root->childnum==1){
        Trans_VarDec_Local(root->child[0]);
    }
    else{
        /*通过root->child[0]->child[0]来获得VarDec的ID,
        通过Trans_exp来获得右值的ID*/
        char name[32];
        strcpy(name,root->child[0]->child[0]->text);
        Operand t1=new_temp();
        Trans_Exp(root->child[2],t1);
        //printf("%d\n",t1->kind);
        InterCode ans3=(InterCode)malloc(sizeof(struct InterCode_));
        Operand left=(Operand)malloc(sizeof(struct Operand_));
        //Operand right=(Operand)malloc(sizeof(struct Operand_));
        left->kind=VARIABLE;
        strcpy(left->u.value,name);
        ans3->kind=W_ASSIGN;
        ans3->u.Assign.left=left;
        ans3->u.Assign.right=t1;
        Inter_insert(ans3);
        if(t1->kind==VAR_CONS||t1->kind==CONSTANT)
            insert_VarconsList(left->u.value,t1->u.var_no);
        
    }
}

void Trans_Cond(Tree* root,int label_true,int label_false)
{
    if(strcmp(root->child[1]->name,"RELOP")==0)
    {
        Operand t1=new_temp();
        Operand t2=new_temp();
        Trans_Exp(root->child[0],t1);
        
        Trans_Exp(root->child[2],t2);
        //code1,code2
        InterCode code3=(InterCode)malloc(sizeof(struct InterCode_));
        code3->kind=W_IFGOTO;
        code3->u.Three.x=t1;
        code3->u.Three.y=t2;
        strcpy(code3->u.Three.relop,root->child[1]->text);
        code3->u.Three.label=create_label(label_true);
        Inter_insert(code3);
        //code3
        InterCode code4=(InterCode)malloc(sizeof(struct InterCode_));
        code4->kind=W_GOTO;
        code4->u.Single.op=create_label(label_false);
        Inter_insert(code4);
        //goto label_false;
    }
    else if(strcmp(root->child[0]->name,"NOT")==0)
    {
        Trans_Cond(root->child[1],label_false,label_true);
    }
    else if(strcmp(root->child[1]->name,"AND")==0)
    {
        Operand label1=new_label();
        int x1=Label_Num;
        Trans_Cond(root->child[0],x1,label_false);
        //code1
        InterCode ans1=(InterCode)malloc(sizeof(struct InterCode_));
        ans1->kind=W_LABEL;
        ans1->u.Single.op=label1;
        Inter_insert(ans1);
        //label1
        Trans_Cond(root->child[2],label_true,label_false);
        //code2
    }
    else if(strcmp(root->child[1]->name,"OR")==0)
    {
        Operand label1=new_label();
        int x1=Label_Num;
        Trans_Cond(root->child[0],label_true,x1);
        //code1
        InterCode ans1=(InterCode)malloc(sizeof(struct InterCode_));
        ans1->kind=W_LABEL;
        ans1->u.Single.op=label1;
        Inter_insert(ans1);
        //label1
        Trans_Cond(root->child[2],label_true,label_false);
        //code2
    }
    else
    {
        Operand t1=new_temp();
        Trans_Exp(root->child[0],t1);
        //code1
        Operand t2=(Operand)malloc(sizeof(struct Operand_));
        t2->kind=CONSTANT;
        t2->u.var_no=0;
        InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
        code2->kind=W_IFGOTO;
        code2->u.Three.x=t1;
        code2->u.Three.y=t2;
        strcpy(code2->u.Three.relop,"!=");
        code2->u.Three.label=create_label(label_true);
        Inter_insert(code2);
        //code2
        Operand label3=create_label(label_false);
        InterCode code3=(InterCode)malloc(sizeof(struct InterCode_));
        code3->kind=W_GOTO;
        code3->u.Single.op=label3;
        Inter_insert(code3);
        //code3
    }
    
}

void Trans_Exp_Struct(Tree *root,Operand place){//结构体访问
    Operand t1=new_temp();
    Operand t2=new_temp();
    Trans_Exp(root->child[0],t1);
    Type type=Exp(root->child[0]);
    strcpy(t2->u.value,root->child[2]->text);
    t2->kind=VARIABLE;
    //HashNode leftnode=check(t1->u.value,0);
    FieldList field=type->u.structure;
    int size=0;
    while(field!=NULL)
    {
        if(strcmp(field->name,t2->u.value)==0)
        {
            break;
        }
        else
        {
            size+=calculate_size(field->type);
            field=field->next;
        }
    }
    //因为函数参数不会出现数组，所以t1->u.value一定是ID
    if(check_param_structure(t1->u.value)==0&&t1->kind!=MYSTAR)
    {   
        //不是函数中的参数，且不是结构体数组
        Operand y=(Operand)malloc(sizeof(struct Operand_));
        Operand temp=(Operand)malloc(sizeof(struct Operand_));
        strcpy(temp->u.value,place->u.value);
        temp->kind=VARIABLE;
        y->kind=CONSTANT;
        y->u.var_no=size;
        t1->kind=TEMP_ADDR;
        InterCode ans=(InterCode)malloc(sizeof(struct InterCode_));
        ans->kind=W_ADD;
        ans->u.Double.op1=t1;
        ans->u.Double.op2=y;
        ans->u.Double.result=temp;
        Inter_insert(ans);
        place->kind=MYSTAR;
    }
    else
    {
        Operand y=(Operand)malloc(sizeof(struct Operand_));
        Operand temp=(Operand)malloc(sizeof(struct Operand_));
        strcpy(temp->u.value,place->u.value);
        temp->kind=VARIABLE;
        y->kind=CONSTANT;
        y->u.var_no=size;
        t1->kind=VARIABLE;
        InterCode ans=(InterCode)malloc(sizeof(struct InterCode_));
        ans->kind=W_ADD;
        ans->u.Double.op1=t1;
        ans->u.Double.op2=y;
        ans->u.Double.result=temp;
        Inter_insert(ans);
        place->kind=MYSTAR;
    }
}

void Trans_Exp(Tree *root,Operand place){
    //Operand place=(Operand)malloc(sizeof(struct Operand_));
    if(root->childnum==1){
        if(strcmp(root->child[0]->name,"ID")==0){
            Trans_Exp_ID(root,place);
        }
        else if(strcmp(root->child[0]->name,"FLOAT")==0){
            //Trans_Exp_FLOAT(root->child[0],place);
        }
        else if(strcmp(root->child[0]->name,"INT")==0){
            Trans_Exp_INT(root->child[0],place);
        }
    }
    else if(root->childnum==2){
        if(strcmp(root->child[0]->name,"MINUS")==0){
            Trans_Exp_MINUS(root,place);
        }
        else if(strcmp(root->child[0]->name,"NOT")==0){
            Trans_Exp_NOT(root,place);
        }
    }
    else if(root->childnum==3){
        if(strcmp(root->child[0]->name,"LP")==0){
            Trans_Exp_LP_RP(root->child[1],place);
        }
        else if(strcmp(root->child[0]->name,"ID")==0){
            Trans_Exp_FuncTrans(root,place);
        }
        else if(strcmp(root->child[0]->name,"Exp")==0){
            if(strcmp(root->child[1]->name,"ASSIGNOP")==0){
                Trans_Exp_ASSIGNOP(root,place);
            }
            else if(strcmp(root->child[1]->name,"AND")==0||strcmp(root->child[1]->name,"OR")==0){
                Trans_Exp_AND_OR(root,place);
            }
            else if(strcmp(root->child[1]->name,"DOT")==0){
                Trans_Exp_Struct(root,place);
            }
            else{
                Trans_Exp_RELOP_and_MATH(root,place);
            }
        }
    }
    else{
        if(strcmp(root->child[0]->name,"ID")==0){
            Trans_Exp_FuncTrans(root,place);
        }  
        else{
            Trans_Exp_Array(root,place);
        }
    }
}
void Trans_Exp_ASSIGNOP(Tree *root,Operand place){
    Operand wxy=new_temp();
    Trans_Exp(root->child[0],wxy);
    
    if(wxy->kind==VAR_CONS){
        wxy->kind=VARIABLE;
        strcpy(wxy->u.value,root->child[0]->child[0]->text);
    }
    Operand temp=new_temp();
    Trans_Exp(root->child[2],temp);
    InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
    code->kind=W_ASSIGN;
    code->u.Assign.left=wxy;
    code->u.Assign.right=temp;
    Inter_insert(code);
    if(wxy->kind==VARIABLE&&state1==0&&state2==0){
        if(temp->kind==CONSTANT||temp->kind==VAR_CONS)
            insert_VarconsList(wxy->u.value,temp->u.var_no);
        else{
            insert_VarconsList(wxy->u.value,0x80000000);
        }
    }
    if(place->kind!=NONE)
    {
        place->kind=wxy->kind;
        strcpy(place->u.value,wxy->u.value);
    }
}
void Trans_Exp_AND_OR(Tree *root,Operand place){
    Operand label1=new_label();
    int mytrue=Label_Num;
    Operand label2=new_label();
    int myfalse=Label_Num;
    Operand zero=(Operand)malloc(sizeof(struct Operand_));
    zero->kind=CONSTANT;
    zero->u.var_no=0;
    Operand one=(Operand)malloc(sizeof(struct Operand_));
    one->kind=CONSTANT;
    one->u.var_no=0;
    InterCode code0=(InterCode)malloc(sizeof(struct InterCode_));
    code0->kind=W_ASSIGN;
    code0->u.Assign.left=place;
    code0->u.Assign.right=zero;
    Inter_insert(code0);
    Trans_Cond(root,mytrue,myfalse);
    InterCode Label_h=(InterCode)malloc(sizeof(struct InterCode_));
    Label_h->kind=LABEL;
    Label_h->u.Single.op=label1;
    Inter_insert(Label_h);
    InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
    code2->kind=W_ASSIGN;
    code2->u.Assign.left=place;
    code2->u.Assign.right=one;
    Inter_insert(code2);
    InterCode Label=(InterCode)malloc(sizeof(struct InterCode_));
    Label->kind=LABEL;
    Label->u.Single.op=label2;
    Inter_insert(Label);
}
void Trans_Exp_RELOP_and_MATH(Tree *root,Operand place){
    if(strcmp(root->child[1]->name,"RELOP")==0){
    Operand label1=new_label();
    int mytrue=Label_Num;
    Operand label2=new_label();
    int myfalse=Label_Num;
    Operand zero=(Operand)malloc(sizeof(struct Operand_));
    zero->kind=CONSTANT;
    zero->u.var_no=0;
    Operand one=(Operand)malloc(sizeof(struct Operand_));
    one->kind=CONSTANT;
    one->u.var_no=0;
    InterCode code0=(InterCode)malloc(sizeof(struct InterCode_));
    code0->kind=W_ASSIGN;
    code0->u.Assign.left=place;
    code0->u.Assign.right=zero;
    Inter_insert(code0);
    Trans_Cond(root,mytrue,myfalse);
    InterCode Label_h=(InterCode)malloc(sizeof(struct InterCode_));
    Label_h->kind=LABEL;
    Label_h->u.Single.op=label1;
    Inter_insert(Label_h);
    InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
    code2->kind=W_ASSIGN;
    code2->u.Assign.left=place;
    code2->u.Assign.right=one;
    Inter_insert(code2);
    InterCode Label=(InterCode)malloc(sizeof(struct InterCode_));
    Label->kind=LABEL;
    Label->u.Single.op=label2;
    Inter_insert(Label);
    }
    else{
        Operand t1=new_temp();
        Trans_Exp(root->child[0],t1);
        Operand t2=new_temp();
        Trans_Exp(root->child[2],t2);
        int flag=0;
        if((t1->kind==CONSTANT||t1->kind==VAR_CONS)&&
            (t2->kind==CONSTANT||t2->kind==VAR_CONS)){
                place->kind=VAR_CONS;
                if(strcmp(root->child[1]->name,"PLUS")==0){
                   place->u.var_no=t1->u.var_no+t2->u.var_no;
                }
                else if(strcmp(root->child[1]->name,"MINUS")==0){
                    place->u.var_no=t1->u.var_no-t2->u.var_no;
                }
                else if(strcmp(root->child[1]->name,"STAR")==0){
                    place->u.var_no=t1->u.var_no*t2->u.var_no;
                }
                else if(strcmp(root->child[1]->name,"DIV")==0){
                    place->u.var_no=t1->u.var_no/t2->u.var_no;
                } 
        }
        else{
            InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
            if(strcmp(root->child[1]->name,"PLUS")==0){
                code2->kind=W_ADD;
            }
            else if(strcmp(root->child[1]->name,"MINUS")==0){
                code2->kind=W_SUB;
            }
            else if(strcmp(root->child[1]->name,"STAR")==0){
                code2->kind=W_MUL;
            }
            else if(strcmp(root->child[1]->name,"DIV")==0){
                code2->kind=W_DIV;
            }
            code2->u.Double.op1=t1;
            code2->u.Double.op2=t2;
            code2->u.Double.result=place;
            Inter_insert(code2);
        }
    }
    
}
void Trans_Exp_LP_RP(Tree *root,Operand place){
    Trans_Exp(root,place);
}
void Trans_Exp_MINUS(Tree *root,Operand place){
    Operand temp=new_temp();
    Trans_Exp(root->child[1],temp);
    if(temp->kind==CONSTANT||temp->kind==VAR_CONS){
        place->kind=VAR_CONS;
        place->u.var_no=(-1)*temp->u.var_no;
    }
    else{
        InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
        Operand op_1=(Operand)malloc(sizeof(struct Operand_));
        op_1->kind=CONSTANT;
        op_1->u.var_no=0;
        code->kind=W_SUB;
        code->u.Double.op1=op_1;
        code->u.Double.op2=temp;
        code->u.Double.result=place;
        Inter_insert(code);
    //place->u.var_no*=(-1);
    }
}
void Trans_Exp_NOT(Tree *root,Operand place){
    Operand label1=new_label();
    int mytrue=Label_Num;
    Operand label2=new_label();
    int myfalse=Label_Num;
    Operand zero=(Operand)malloc(sizeof(struct Operand_));
    zero->kind=CONSTANT;
    zero->u.var_no=0;
    Operand one=(Operand)malloc(sizeof(struct Operand_));
    one->kind=CONSTANT;
    one->u.var_no=0;
    InterCode code0=(InterCode)malloc(sizeof(struct InterCode_));
    code0->kind=W_ASSIGN;
    code0->u.Assign.left=place;
    code0->u.Assign.right=zero;
    Inter_insert(code0);
    Trans_Cond(root,mytrue,myfalse);
    InterCode Label_h=(InterCode)malloc(sizeof(struct InterCode_));
    Label_h->kind=LABEL;
    Label_h->u.Single.op=label1;
    Inter_insert(Label_h);
    InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
    code2->kind=W_ASSIGN;
    code2->u.Assign.left=place;
    code2->u.Assign.right=one;
    Inter_insert(code2);
    InterCode Label=(InterCode)malloc(sizeof(struct InterCode_));
    Label->kind=LABEL;
    Label->u.Single.op=label2;
    Inter_insert(Label);
}
void Trans_Exp_FuncTrans(Tree *root,Operand place){//函数调用
    //printf("haha\n");
    char funcname[32];
    strcpy(funcname,root->child[0]->text);
    //printf("%s\n",funcname);
    HashNode checknode=check(funcname,1);
    HashNode checknode_var=check(funcname,0);
    if(checknode==NULL){
        ;//There will not be an error.
    }
    else{
        if(root->childnum==3){
            if(strcmp(funcname,"read")==0){
                InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
                code->kind=W_READ;
                code->u.Single.op=place;
                Inter_insert(code);
            }
            else{
                Operand name=(Operand)malloc(sizeof(struct Operand_));
                name->kind=MYFUNCTION;
                strcpy(name->u.value,funcname);
                InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
                code->kind=W_CALL;
                code->u.Assign.right=name;
                code->u.Assign.left=place;
                Inter_insert(code);
            }
        }
        else{
            Arg_list Arg=Trans_Args(root->child[2]);
            if(strcmp(funcname,"write")==0){
                InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
                code->kind=W_WRITE;
                code->u.Single.op=Arg->arg;
                Inter_insert(code);
            }
            else{
                while(Arg!=NULL){
                    InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
                    code->kind=W_ARG;
                    code->u.Single.op=Arg->arg;
                    Inter_insert(code);
                    Arg=Arg->next;
                }
                Operand name=(Operand)malloc(sizeof(struct Operand_));
                name->kind=MYFUNCTION;
                strcpy(name->u.value,funcname);
                InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
                code->kind=W_CALL;
                code->u.Assign.left=place;
                code->u.Assign.right=name;
                Inter_insert(code);
            }
        }
    }
}
void Trans_Exp_Array(Tree *root,Operand place){//数组访问
   
    Operand value=new_temp();
    Trans_Exp(root->child[2],value);
    Operand exp1=new_temp();
    Trans_Exp(root->child[0],exp1);
    Operand temp=new_temp();
    temp->kind=place->kind;
    strcpy(temp->u.value,place->u.value);
    InterCode code0=(InterCode)malloc(sizeof(struct InterCode_));
    code0->kind=W_ADD;
    if(exp1->kind!=MYSTAR)
        exp1->kind=VAR_ADDR;
    else{
        /*
        Operand temp_exp1=(Operand)malloc(sizeof(struct Operand_));
        temp_exp1->kind=VARIABLE;
        strcpy(temp_exp1->u.value,exp1->u.value);*/
        exp1->kind=VARIABLE;
    }
    code0->u.Double.op1=exp1;
    if(value->kind==CONSTANT){
        value->u.var_no=4*value->u.var_no;
        code0->u.Double.op2=value;
    }
    else{
        Operand temp1=new_temp();
        Operand cons=(Operand)malloc(sizeof(struct Operand_));
        cons->kind=CONSTANT;
        //calculate size of the array.
        Type type=Exp(root->child[0]);
        cons->u.var_no=calculate_size(type->u.array.elem);//TO BE MODIFIED
        InterCode code1=(InterCode)malloc(sizeof(struct InterCode_));
        code1->kind=W_MUL;
        code1->u.Double.op1=cons;
        code1->u.Double.op2=value;
        code1->u.Double.result=temp1;
        Inter_insert(code1);
        code0->u.Double.op2=temp1;
    }
    
    code0->u.Double.result=temp;
    Inter_insert(code0);//The address has been calculated.
    place->kind=MYSTAR;
}

void Trans_Exp_ID(Tree *root,Operand place){
    HashNode checknode=check(root->child[0]->text,0);
    HashNode checknode1=check(root->child[0]->text,1);
    if(checknode==NULL&&checknode1==NULL){
        ;//There will not be an error.
    }
    else{   
        int result=check_VarconsList(checknode->name);
        if(result!=0x80000000&&state==0&&state1==0&&state2==0){
            place->kind=VAR_CONS;
            place->u.var_no=result;
        }
        else{
            if(state1!=0||state2!=0){
                insert_VarconsList(root->child[0]->text,0x80000000);
            }
            place->kind=VARIABLE;
            strcpy(place->u.value,root->child[0]->text);
        }
    }
}
void Trans_Exp_INT(Tree *root,Operand place){
    /*InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
    Operand cons=(Operand)malloc(sizeof(struct Operand_));
    cons->kind=CONSTANT;
    cons->u.var_no=string_to_int(root->text);
    code->kind=W_ASSIGN;
    code->u.Assign.left=place;
    code->u.Assign.right=cons;
    Inter_insert(code);*/
    place->kind=CONSTANT;
    place->u.var_no=string_to_int(root->text);
}

Arg_list Trans_Args(Tree *root){
    Arg_list Arg=NULL;
    while(root->childnum>1){
        Operand t1=new_temp();
        Trans_Exp(root->child[0],t1);
        Type type=Exp(root->child[0]);
        if(type->kind==STRUCTURE){
            t1->kind=VAR_ADDR;
        }
        Arg_list newArg=(Arg_list)malloc(sizeof(struct Arg_list_));
        newArg->arg=t1;
        newArg->next=Arg;
        Arg=newArg;
        root=root->child[2];
    }
    Operand t1=new_temp();
    Trans_Exp(root->child[0],t1);
    Arg_list newArg=(Arg_list)malloc(sizeof(struct Arg_list_));
    newArg->arg=t1;
    newArg->next=Arg;
    Arg=newArg;
    return Arg;
}

int check_param_structure(char* str){
    Param_Struc point=param_head;
    while(point!=NULL){
        if(strcmp(point->name,str)==0)
            break;
        point=point->next;
    }
    if(point==NULL)
        return 0;
    return 1;
}
void insert_param_structure(char *str){
    Param_Struc newparam=(Param_Struc)malloc(sizeof(struct Param_Struc_));
    strcpy(newparam->name,str);
    newparam->next=param_head;
    param_head=newparam;
}
void insert_VarconsList(char* str,int cons){
    Varcons_list point=var_head;
    while(point!=NULL){
        if(strcmp(point->name,str)==0)
            break;
        point=point->next;
    }
    //全新的变量
    if(point==NULL){
        Varcons_list newvar=(Varcons_list)malloc(sizeof(struct Varcons_list_));
        strcpy(newvar->name,str);
        newvar->value=cons;
        newvar->next=var_head;
        var_head=newvar;
    }
    //对原来的变量进行更新
    else{
        point->value=cons;
    }
    
}
int check_VarconsList(char* str){
    Varcons_list point=var_head;
    while(point!=NULL){
        if(strcmp(point->name,str)==0)
            break;
        point=point->next;
    }
    if(point==NULL){
        return 0x80000000;
    }
    return point->value;
}

void Inter_delete(InterCode a)
{
    if(a==code_head&&a==code_tail)
    {
        //free(a);
        code_head=NULL;
        code_tail=NULL;
    }
    else if(a==code_head)
    {
        code_head=a->next;
        code_head->pre=NULL;
        //free(a);
    }
    else if(a==code_tail)
    {
        code_tail=a->pre;
        code_tail->next=NULL;
        //free(a);
    }
    else
    {
        a->pre->next=a->next;
        a->next->pre=a->pre;
        //free(a);
    }
}
void myfree(InterCode a)
{
    if(a->kind==W_IFGOTO)
    {
        free(a->u.Three.x);
        free(a->u.Three.y);
        free(a->u.Three.label);
        free(a);
    }
    else if(a->kind==W_LABEL||a->kind==W_GOTO)
    {
        free(a->u.Single.op);
        free(a);
    }
    else if(a->kind==W_ASSIGN)
    {
        free(a->u.Assign.left);
        free(a->u.Assign.right);
        free(a);
    }
    else
    {
        free(a->u.Double.op1);
        free(a->u.Double.op2);
        free(a->u.Double.result);
        free(a);
    }
}
void delete_goto()
{
    InterCode head=code_head;
    for(;head!=NULL;head=head->next)
    {
        if(head->kind==W_IFGOTO)
        {
            InterCode a=head;
            InterCode b=head->next;
            if(b==NULL)
            continue;
            InterCode c=b->next;
            if(c==NULL)
            continue;
            if(b->kind==W_GOTO&&strcmp(a->u.Three.label->u.value,c->u.Single.op->u.value)==0)
            {
                strcpy(a->u.Three.label->u.value,b->u.Single.op->u.value);
                Inter_delete(b);
                //free(b->u.Single.op);
                //free(b);
                if(strcmp(a->u.Three.relop,"==")==0)
                {
                    strcpy(a->u.Three.relop,"!=");
                }
                else if(strcmp(a->u.Three.relop,"!=")==0)
                {
                    strcpy(a->u.Three.relop,"==");
                }
                else if(strcmp(a->u.Three.relop,">=")==0)
                {
                    strcpy(a->u.Three.relop,"<");
                }
                else if(strcmp(a->u.Three.relop,"<=")==0)
                {
                    strcpy(a->u.Three.relop,">");
                }
                else if(strcmp(a->u.Three.relop,">")==0)
                {
                    strcpy(a->u.Three.relop,"<=");
                }
                else if(strcmp(a->u.Three.relop,"<")==0)
                {
                    strcpy(a->u.Three.relop,">=");
                }
            }
        }
        else if(head->kind==W_GOTO)
        {
                InterCode a=head;
                InterCode b=head->next;
                if(b==NULL)
                continue;
                if(b->kind==W_LABEL&&strcmp(a->u.Single.op->u.value,b->u.Single.op->u.value)==0)
                {
                    Inter_delete(a);
                }
        }
    }
}
void delete_label()
{
    InterCode head=code_head;
    Label_Node Label_head=NULL;
    Label_Node Label_tail=NULL;
    while(head!=NULL)
    {
        if(head->kind==W_GOTO||head->kind==W_IFGOTO)
        {
            //printf("wxy\n");
            //insert_Label_Node(head->u.Single.op->u.value);
            Label_Node wxy=(Label_Node)malloc(sizeof(struct Label_Node_));
            if(head->kind==W_GOTO)
            strcpy(wxy->name,head->u.Single.op->u.value);
            else
            {
                strcpy(wxy->name,head->u.Three.label->u.value);
            }
            //printf("www\n");
            if(Label_head==NULL)
            {
                Label_head=wxy;
                Label_tail=wxy;
                Label_tail->next=NULL;
            }
            else
            {
                Label_tail->next=wxy;
                wxy->next=NULL;
                Label_tail=wxy;
            }      
        }
        //printf("kkk\n");
        head=head->next;
    }
    //printf("hhh\n");
    head=code_head;
    while(head!=NULL)
    {
        if(head->kind==W_LABEL)
        {
            Label_Node temp=Label_head;
            while(temp!=NULL)
            {
                if(strcmp(temp->name,head->u.Single.op->u.value)==0)
                {
                    break;
                }
                temp=temp->next;
            }
            InterCode a=head;
            head=head->next;
            if(temp==NULL)
            {
                Inter_delete(a);
            }
        }
        else
        {
            head=head->next;
        }
        
    }
}
void merge_label()
{
    InterCode head=code_head;
    while(head!=NULL)
    {
        Label_Node Label_head=NULL;
        Label_Node Label_tail=NULL;
        if(head->kind==W_LABEL)
        {
            Label_Node ssh=(Label_Node)malloc(sizeof(struct Label_Node_));
            strcpy(ssh->name,head->u.Single.op->u.value);
            Label_head=ssh;
            Label_tail=ssh;
            Label_tail->next=NULL;
            head=head->next;
            while(head!=NULL&&head->kind==W_LABEL)
            {
                Label_Node wxy=(Label_Node)malloc(sizeof(struct Label_Node_));
                strcpy(wxy->name,head->u.Single.op->u.value);
                Label_tail->next=wxy;
                wxy->next=NULL;
                Label_tail=wxy;
                InterCode a=head;
                head=head->next;
                Inter_delete(a);
            }
            if(Label_head->next!=NULL)
            {
                InterCode temp=code_head;
                while(temp!=NULL){
                    if(temp->kind==W_GOTO||temp->kind==W_IFGOTO)
                    {
                        char myname[32];
                        if(temp->kind==W_GOTO)
                        strcpy(myname,temp->u.Single.op->u.value);
                        else strcpy(myname,temp->u.Three.label->u.value);
                        Label_Node hhh=Label_head;
                        while(hhh!=NULL)
                        {
                            if(strcmp(hhh->name,myname)==0)
                            {
                                if(temp->kind==W_GOTO)
                                    strcpy(temp->u.Single.op->u.value,Label_head->name);
                                    else
                                    strcpy(temp->u.Three.label->u.value,Label_head->name);

                                break;
                            }
                            hhh=hhh->next;
                        }
                    }
                temp=temp->next;
                }
            }
        }
        else head=head->next;
    }
}

void delete_public(){
    InterCode point=code_head;
    while(point!=NULL){
        InterCode final=next_firstintr(point);
        while(point!=final){
            if(point->kind==W_ADD&&(point->u.Double.op1->kind==VAR_ADDR)){
                if(check(point->u.Double.op1->u.value,0)->val->kind==ARRAY){//对于point这条语句中的数组，向下找
                        point=point->next;
                        continue;
                }
            }
               
            Operand point_left=GetExprLeft(point);
            if(point_left==NULL||point_left->kind!=TEMP_VAR){
                point=point->next;
                continue;
            }
            InterCode next = point->next;
            while (next != final) {
                if (isIntercodeEqual(point, next) == 1) {
                    InterCode check_if_modified=point->next;
                    //检查在这个过程中表达式的右边是否出现在了左值位置
                    while(check_if_modified!=next){
                        if(check_if_modified->kind==W_ASSIGN||check_if_modified->kind == W_ADD ||
                        check_if_modified->kind == W_SUB || check_if_modified->kind == W_MUL ||
                        check_if_modified->kind == W_DIV){
                            Operand check=GetExprLeft(check_if_modified);
                            if(point->kind==W_ASSIGN){
                                if(isOperangEqual(check,point->u.Assign.right)==1)
                                    break;
                            }
                            else if(point->kind == W_ADD || point->kind == W_SUB || point->kind == W_MUL || point->kind == W_DIV){
                                if(isOperangEqual(check,point->u.Double.op1)==1||isOperangEqual(check,point->u.Double.op2)==1){
                                    break;
                                }
                            }
                        }
                        check_if_modified=check_if_modified->next;
                    }
                    //如果公共子表达式的值已经出现了不同，那也不用继续往下找了,直接point=point->next即可
                    if(check_if_modified!=next){
                        break;
                    }
                    InterCode doubtful = next->next;
                    while (doubtful != final) {
                        if (isDoubtfulEqual(next, doubtful) == 1)
                            break;
                        doubtful = doubtful->next;
                    }
                    //
                    InterCode index=next;
                    InterCode to_be_deleted=next;
                    Operand instead = GetExprLeft(point);
                    Operand temp=(Operand)malloc(sizeof(struct Operand_));
                    temp->kind=instead->kind;
                    strcpy(temp->u.value,instead->u.value);
                    Operand next_insteaded = (Operand)malloc(sizeof(struct Operand_));
                    next_insteaded->kind=TEMP_VAR;
                    Operand fuck=GetExprLeft(next);
                    strcpy(next_insteaded->u.value,fuck->u.value);
                    
                    while (index != doubtful) {
                        if(index->kind==W_ASSIGN){
                            if(index->u.Assign.right->kind!=VAR_CONS&&index->u.Assign.right->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Assign.right->u.value)==0){
                                    strcpy(index->u.Assign.right->u.value,temp->u.value);
                                }
                                if(strcmp(next_insteaded->u.value,index->u.Assign.left->u.value)==0){
                                    strcpy(index->u.Assign.left->u.value,temp->u.value);
                                }
                            }
                        }
                        else if(index->kind == W_ADD || index->kind == W_SUB || index->kind == W_MUL || index->kind == W_DIV){
                            if(index->u.Double.op1->kind!=VAR_CONS&&index->u.Double.op1->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Double.op1->u.value)==0){
                                    strcpy(index->u.Double.op1->u.value,temp->u.value);
                                }
                            }
                            if(index->u.Double.op2->kind!=VAR_CONS&&index->u.Double.op2->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Double.op2->u.value)==0){
                                    strcpy(index->u.Double.op2->u.value,temp->u.value);
                                }
                            }
                            if(index->u.Double.result->kind!=VAR_CONS&&index->u.Double.result->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Double.result->u.value)==0){
                                    strcpy(index->u.Double.result->u.value,temp->u.value);
                                }
                            }
                        }
                        else if(index->kind==W_IFGOTO){
                            if(index->u.Three.x->kind!=VAR_CONS&&index->u.Three.x->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Three.x->u.value)==0){
                                strcpy(index->u.Three.x->u.value,temp->u.value);
                                }
                            }
                            if(index->u.Three.y->kind!=VAR_CONS&&index->u.Three.y->kind!=CONSTANT){
                                if(strcmp(next_insteaded->u.value,index->u.Three.y->u.value)==0){
                                    strcpy(index->u.Three.y->u.value,temp->u.value);
                                }
                            }
                        }
                        else if(index->kind==W_ARG){
                            if(strcmp(index->u.Single.op->u.value,next_insteaded->u.value)==0){
                                strcpy(index->u.Single.op->u.value,temp->u.value);
                            }
                        }
                        index=index->next;
                    }
                    next=next->next;
                    Inter_delete(to_be_deleted);
                    continue;
                }
                next = next->next;
            }
            point=point->next;
        }
        //count++;
    }
}
int isIntercodeEqual(InterCode code1,InterCode code2){
    /*if(code1->kind==W_MUL){
        printOperand(code1->u.Double.result);
    }*/
    if(code1->kind==code2->kind){
        //printf("kind %d  %d",)
        if(code1->kind==W_ADD||code1->kind==W_MUL){
            if((isOperangEqual(code1->u.Double.op1,code2->u.Double.op2)==1)&&
                (isOperangEqual(code1->u.Double.op2,code2->u.Double.op1)==1))
                {
                    return 1;
                }
            else if((isOperangEqual(code1->u.Double.op1,code2->u.Double.op1)==1)&&
                (isOperangEqual(code1->u.Double.op2,code2->u.Double.op2)==1))
                {
                    return 1;
                }
        }
        else if(code1->kind==W_SUB||code1->kind==W_DIV){
            if(isOperangEqual(code1->u.Double.op1,code2->u.Double.op1)==1){
                if(isOperangEqual(code1->u.Double.op2,code2->u.Double.op2)==1){
                    return 1;
                }
            }
        }
        else if(code1->kind==W_ASSIGN){
            if(isOperangEqual(code1->u.Assign.right,code2->u.Assign.right)==1)
                return 1;
        }
    }
    return 0;
}
int isDoubtfulEqual(InterCode code1,InterCode code2){
    if(code1->kind==code2->kind){
        if(code1->kind==W_ADD||code1->kind==W_MUL||code1->kind==W_SUB||code1->kind==W_DIV){
            if(isOperangEqual(code1->u.Double.result,code2->u.Double.result)==1){
                return 1;
            }   
        }
        else if(code1->kind==W_ASSIGN){
            if(isOperangEqual(code1->u.Assign.left,code2->u.Assign.left)==1)
                return 1;
        }
    }
    return 0;
}
int isOperangEqual(Operand op1,Operand op2){
    if(op1->kind==op2->kind){
        if(op1->kind==VAR_CONS||op1->kind==CONSTANT){
            if(op1->u.var_no==op2->u.var_no)
                return 1;
        }
        else {
            if(strcmp(op1->u.value,op2->u.value)==0)
                return 1;
        }
    }
    return 0;
}
Operand GetExprLeft(InterCode code){
    if(code->kind==W_ASSIGN){
        return code->u.Assign.left;
    }
    else if(code->kind == W_ADD || code->kind == W_SUB || code->kind == W_MUL || code->kind == W_DIV){
        return code->u.Double.result;
    }
    return NULL;
}
void printInter(InterCode head){
    if(head->kind==W_LABEL){
            printf("LABEL %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_FUNCTION){
            printf("FUNCTION %s :\n",head->u.Single.op->u.value);
        }
        else if(head->kind==W_ASSIGN){
            printOperand(head->u.Assign.left);
            printf(" := ");
            printOperand(head->u.Assign.right);
            printf("\n");
        }
        else if(head->kind==W_ADD||head->kind==W_SUB||head->kind==W_MUL||head->kind==W_DIV){
            printOperand(head->u.Double.result);
            printf(" := ");
            printOperand(head->u.Double.op1);
            if(head->kind==W_ADD){
                printf(" + ");
            }
            else if(head->kind==W_SUB){
                printf(" - ");
            }
            else if(head->kind==W_MUL){
                printf(" * ");
            }
            else if(head->kind==W_DIV){
                printf(" / ");
            }
            printOperand(head->u.Double.op2);
            printf("\n");
        }
        else if(head->kind==W_GOTO){
            printf("GOTO ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_IFGOTO){
            printf("IF ");
            printOperand(head->u.Three.x);
            printf(" %s ",head->u.Three.relop);
            printOperand(head->u.Three.y);
            printf(" GOTO ");
            printOperand(head->u.Three.label);
            printf("\n");
        }
        else if(head->kind==W_RETURN){
            printf("RETURN ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_DEC){
            printf("DEC ");
            printOperand(head->u.Dec.op);
            printf(" %d\n",head->u.Dec.size);
        }
        else if(head->kind==W_ARG){
            printf("ARG ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_CALL){
            printOperand(head->u.Assign.left);
            printf(" := CALL ");
            printOperand(head->u.Assign.right);
            printf("\n");
        }
        else if(head->kind==W_PARAM){
            printf("PARAM ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_READ){
            printf("READ ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
        else if(head->kind==W_WRITE){
            printf("WRITE ");
            printOperand(head->u.Single.op);
            printf("\n");
        }
}

InterCode next_firstintr(InterCode a)
{
    InterCode pre=a;
    if(a==NULL)
    return NULL;
    a=a->next;
    while(a!=NULL)
    {
        if(a->kind==W_LABEL)
        {
            return a;
        }
        else if(pre->kind==W_GOTO||pre->kind==W_IFGOTO){
            return a;
        }
        else if(a->kind==W_FUNCTION){
            return a;
        }
        pre=a;
        a=a->next;
    }
    return NULL;
}