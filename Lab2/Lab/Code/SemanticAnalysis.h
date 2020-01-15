#ifndef SEMANTICANALYSIS_H
#define SEMANTICANALYSIS_H
#include"tree.h"
#include<string.h>
typedef struct Type_* Type;  
typedef struct FieldList_* FieldList;  
typedef struct FuncList_* FuncList;
typedef struct HashNode_* HashNode;
#define HASHTABLESIZE 0x3fff
#define TYPE_INT 0
#define TYPE_FLOAT 1
extern HashNode SymbolTable[HASHTABLESIZE];

struct Type_  
{  
    enum { BASIC, ARRAY, STRUCTURE, FUNCTION, ERROR } kind;  
    union  
    {   
        //struct A x;//其中x是UserDef,A是Structure
        // 基本类型       
        int basic;       
        // 数组类型信息包括元素类型与数组大小构成 
        struct { Type elem; int size; } array; 
        // 结构体类型信息是一个链表      
        FieldList structure; 
        //函数名
        FuncList myfunc;
        //错误类型
        int error_type;
    }u;
};
struct FieldList_
{
    char name[32];//域名
    Type type;//域类型
    FieldList next;
};
struct FuncList_
{
    char name[32];//函数名,参数名  
    Type type;//返回类型,参数的类型   
    FuncList next;
};
struct HashNode_
{
    char name[32];//节点名称
    Type val;//节点类型
    HashNode next;//哈希值相同的下一个节点
};

void Program(Tree *root);

void ExtDefList(Tree *root);
 
void ExtDef(Tree *root);

Type Specifier(Tree *root);
Type StructSpecifier(Tree *root);

/*Definition about struct*/
void DefList_in_Struct(Tree *root,FieldList head);//在此函数中判断结构体内域名重复,就是从Def_in_Struct中返回的节点，要采用尾插，然后在向尾部遍历的过程中检查
FieldList Def_in_Struct(Tree *root);
FieldList DecList_in_Struct(Tree*root,Type dec_type);
FieldList Dec_in_Struct(Tree *root,Type dec_type);

/*Definition in Function*/
void FunDec(Tree *root,const Type return_type);
FuncList VarList(Tree *root);
FuncList ParamDec(Tree *root);
void DefList_in_Function(Tree *root);
void Def_in_Function(Tree *root);
void DecList_in_Function(Tree *root,Type dec_type);/*Def->Specifier DecList SEMI中Specifier的类型*/
void Dec_in_Function(Tree *root,Type dec_type);

/*Declarition*/
//Type VarDec(Tree *root,Type type,char *ID);//如果是ID，就返回参数中的type；如果是数组，就返回一个头结点
HashNode VarDec(Tree *root,Type type);
void ExtDecList(Tree *root,Type type);

/*Expression*/
void Compst(Tree *root,Type return_type);
void StmtList(Tree *root,Type return_type);
void Stmt(Tree *root,Type return_type);
/*void Stmt_RETURN(Tree *root,Type return_type);
void Stmt_IF(Tree *root,Type return_type);//判断Exp的类型
void Stmt_WHILE(Tree *root,Type return_type);//判断Exp的类型*/
Type Exp(Tree *root);
Type Exp_ASSIGNOP(Tree *root);
Type Exp_AND_OR(Tree *root);
Type Exp_RELOP_and_MATH(Tree *root);
Type Exp_LP_RP(Tree *root);
Type Exp_MINUS(Tree *root);
Type Exp_NOT(Tree *root);
Type Exp_FuncTrans(Tree *root);//函数调用
Type Exp_Array(Tree *root);//数组访问
Type Exp_Struct(Tree *root);//结构体访问
Type Exp_ID(Tree *root);
Type Exp_INT(Tree *root);
Type Exp_FLOAT(Tree *root);
int Args(Tree *root,FuncList func);

#endif