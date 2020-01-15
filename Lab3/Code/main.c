#include<stdio.h>
#include"syntax.tab.h"
#include"tree.h"
#include"SemanticAnalysis.h"
#include"HelpFunc.h"
#include"Intercode.h"
#include"SymbolTable.h"
#include<stdlib.h>
extern HashNode SymbolTable[HASHTABLESIZE];
InterCode code_head=NULL;
InterCode code_tail=NULL;
Param_Struc param_head=NULL;
Varcons_list var_head=NULL;
int Label_Num=0;
int Temp_Num=0;
int mistake=0;
FILE* fp;
extern Tree* ROOT;
extern void yyrestart  (FILE * input_file );
extern int yyparse (void);
void init_table(){
    for(int i=0;i<HASHTABLESIZE;i++){
        SymbolTable[i]=NULL;
    }
    HashNode read=(HashNode)malloc(sizeof(struct HashNode_));
    strcpy(read->name,"read");
    read->next=NULL;
    Type func_read=(Type)malloc(sizeof(struct Type_));
    func_read->kind=FUNCTION;
    FuncList myread=(FuncList)malloc(sizeof(struct FuncList_));
    strcpy(myread->name,"read");
    Type INT1=(Type)malloc(sizeof(struct Type_));
    INT1->kind=BASIC;
    INT1->u.basic=TYPE_INT;
    myread->next=NULL;
    myread->type=INT1;
    read->val=func_read;
    func_read->u.myfunc=myread;
    insertnode(read);

    HashNode write=(HashNode)malloc(sizeof(struct HashNode_));
    strcpy(write->name,"write");
    write->next=NULL;
    Type func_write=(Type)malloc(sizeof(struct Type_));
    func_write->kind=FUNCTION;
    FuncList mywrite=(FuncList)malloc(sizeof(struct FuncList_));
    FuncList mywrite_param=(FuncList)malloc(sizeof(struct FuncList_));
    strcpy(mywrite->name,"write");
    Type INT2=(Type)malloc(sizeof(struct Type_));
    Type INT3=(Type)malloc(sizeof(struct Type_));
    INT2->kind=BASIC;
    INT3->kind=BASIC;
    INT2->u.basic=TYPE_INT;
    INT3->u.basic=TYPE_INT;
    mywrite->type=INT2;
    strcpy(mywrite_param->name,"MYWRITEPARAM");
    mywrite_param->next=NULL;
    mywrite_param->type=INT3;
    mywrite->next=mywrite_param;
    write->val=func_write;
    func_write->u.myfunc=mywrite;
    insertnode(write);
}
int main(int argc,char** argv)
{
    init_table();
    if(argc<=1)
        return 1;
    FILE* f=fopen(argv[1],"r");
    fp=fopen(argv[2],"w+");
    if(!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    /*if(mistake==0){
        Treeprint(ROOT,0);
    }*/  
    Program(ROOT);
    Trans_Program(ROOT);
    merge_label();
    delete_goto();
    delete_label();
    delete_public();
    if(mistake==0){
       // while(1);
        printIR(code_head);
    }

    return 0;
}