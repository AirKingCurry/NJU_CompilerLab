/* Helpful Function*/
#ifndef HELPFUNC_H
#define HELPFUNC_H
#include"SemanticAnalysis.h"
Type mycopy_type(Type temp);
FieldList mycopy_structure(FieldList temp);
FuncList mycopy_func(FuncList temp);
int string_to_int(char* temp);
void output_type(Type temp);
void output_fieldlist(FieldList temp);
void output_func(FuncList temp);
int isTypeEqual(Type a,Type b);
int IsStructureEqual(FieldList a,FieldList b);
int IsFuncEqual(FuncList a,FuncList b);

#endif