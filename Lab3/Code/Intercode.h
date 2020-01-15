#ifndef _INTERCODE_H
#define _INTERCODE_H

typedef struct Operand_* Operand;
typedef struct InterCode_* InterCode;
typedef struct Arg_list_* Arg_list;
typedef struct Param_Struc_* Param_Struc;
typedef struct Varcons_list_* Varcons_list;
typedef struct Label_Node_* Label_Node;
InterCode code_head;
InterCode code_tail;
Param_Struc param_head;
Varcons_list var_head;
int Label_Num;
int Temp_Num;

typedef struct Operand_{

	enum{TEMP_VAR,VARIABLE,CONSTANT,LABEL,MYFUNCTION,VAR_ADDR,TEMP_ADDR,MYSTAR,NONE,VAR_CONS}kind;
	//VAR_CONS 它是一个变量，但是这个变量的值可计算，故把这个变量当成常量考虑
	union{
		int var_no;//CONSTANT
		//int cons_instead_var;
		char value[32];
		Operand addr;
	}u;
} Operand_;

typedef struct InterCode_{
    enum{W_LABEL,W_FUNCTION,W_ASSIGN,W_ADD,W_SUB,W_MUL,W_DIV,W_GETADDR,W_GETVALUE,W_VALUEGOT,W_GOTO,
    W_IFGOTO,W_RETURN,W_DEC,W_ARG,W_CALL,W_PARAM,W_READ,W_WRITE}kind;
	union{
		struct{	Operand op;	}Single;
		struct{ Operand op1,op2,result; }Double;
		struct{ Operand x; Operand y; Operand label; char relop[32]; }Three;
        struct{ Operand left,right; }Assign;
		struct{ Operand op; int size; }Dec;
	}u;
	InterCode pre;
	InterCode next;
} InterCode_;

typedef struct Arg_list_{
    Operand arg;
    Arg_list next;
}Arg_list_;

typedef struct Param_Struc_{
    char name[32];
    Param_Struc next;
}Param_Struc_;

typedef struct Varcons_list_{
	char name[32];
	int value;
	Varcons_list next;
}Varcons_list_;

typedef struct Label_Node_{
	char name[32];
	Label_Node next;
}Label_Node_;

void Inter_delete(InterCode a);
void myfree(InterCode a);
void delete_goto();
void delete_label();
void merge_label();

InterCode next_firstintr(InterCode a);
void printInter(InterCode head);
Operand GetExprLeft(InterCode code);
int isDoubtfulEqual(InterCode code1,InterCode code2);
int isOperangEqual(Operand op1,Operand op2);
int isIntercodeEqual(InterCode code1,InterCode code2);
void delete_public();
void insert_VarconsList(char* str,int cons);
int check_VarconsList(char* str);
int check_param_structure(char* str);
void insert_param_structure(char *str);
int calculate_size(Type temp);
void Inter_insert(InterCode a);
Operand new_temp();
Operand new_label();
Operand create_label(int x);
void Trans_Program(Tree *root);

void Trans_ExtDefList(Tree *root);
 
void Trans_ExtDef(Tree *root);


/*Definition in Function*/
void Trans_FunDec(Tree *root);
void Trans_VarList(Tree *root);
void Trans_ParamDec(Tree *root);
void Trans_DefList_in_Function(Tree *root);
void Trans_Def_in_Function(Tree *root);
void Trans_DecList_in_Function(Tree *root);/*Def->Specifier DecList SEMI中Specifier的类型*/
void Trans_Dec_in_Function(Tree *root);
void Trans_ExtDecList(Tree* root);
/*Declarition*/
//Type VarDec(Tree *root,Type type,char *ID);//如果是ID，就返回参数中的type；如果是数组，就返回一个头结点
void Trans_VarDec(Tree *root);
void Trans_VarDec_Func(Tree *root);
/*Expression*/
void Trans_Compst(Tree *root);
void Trans_StmtList(Tree *root);
void Trans_Stmt(Tree *root);

void Trans_Exp(Tree *root,Operand place);
void Trans_Exp_ASSIGNOP(Tree *root,Operand place);
void Trans_Exp_AND_OR(Tree *root,Operand place);
void Trans_Exp_RELOP_and_MATH(Tree *root,Operand place);
void Trans_Exp_LP_RP(Tree *root,Operand place);
void Trans_Exp_MINUS(Tree *root,Operand place);
void Trans_Exp_NOT(Tree *root,Operand place);
void Trans_Exp_FuncTrans(Tree *root,Operand place);//函数调用
void Trans_Exp_Array(Tree *root,Operand place);//数组访问
void Trans_Exp_Struct(Tree *root,Operand place);//结构体访问
void Trans_Exp_ID(Tree *root,Operand place);
void Trans_Exp_INT(Tree *root,Operand place);
void Trans_Exp_FLOAT(Tree *root,Operand place);
Arg_list Trans_Args(Tree *root);

void Trans_Cond(Tree* root,int label_true,int label_false);

void printIR(InterCode head);


#endif