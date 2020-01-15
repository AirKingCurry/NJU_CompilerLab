#ifndef OBJECTCODE_H
#define OBJECTCODE_H
#include"Intercode.h"
typedef struct Var_* Var;
struct Register
{
    char name[32];
    int free;
    Var variables;
}regs[32];
typedef struct Var_
{
    char name[32];
    int reg;
    int offset;
    Var next;
}Var_;

void Trans_final(InterCode head,char*filename);
void init_regs();
int get_regs(Operand x);
Var check_var(Operand x);
void Load_Memory(int reg);//Load variable x to memory
int find_freereg();
void init_final();
void insert_newvar(Var temp);

void Trans_final_WRITE(InterCode head);
void Trans_final_READ(InterCode head);
void Trans_final_Label(InterCode head);
void Trans_final_ADD(InterCode head);
void Trans_final_SUB(InterCode head);
void Trans_final_MUL(InterCode head);
void Trans_final_DIV(InterCode head);
void Trans_final_ASSIGN(InterCode head);
void Trans_final_GOTO(InterCode head);
void Trans_final_ARG_CALL(InterCode head);
void Trans_final_RETURN(InterCode head);
void Trans_final_IFGOTO(InterCode head);
void Trans_final_FUNCTION(InterCode head);
//void Trans_final_Dec(InterCode head);
void sub_sp(Operand x);
#endif