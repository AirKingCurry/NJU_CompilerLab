
%{
    #include<stdio.h>
    #include "lex.yy.c"
    #include"tree.h"
    void yyerror(char* msg);
    extern Tree* ROOT;
    int misline[4096]={0};
%}

/*declared types*/
%union
{
    /*int type_int;
    float type_float;
    double type_double;
    char type_char;
    char* type_string;*/
    struct TREE* type_tree;
}
%token <type_tree> INT
%token <type_tree> FLOAT
%token <type_tree> ID
%token <type_tree> SEMI
%token <type_tree> COMMA
%token <type_tree> ASSIGNOP
%token <type_tree> RELOP
%token <type_tree> PLUS MINUS  STAR DIV
%token <type_tree> AND OR 
%token <type_tree> NOT
%token <type_tree> DOT
%token <type_tree> TYPE
%token <type_tree> LP RP LB RB LC RC
%token <type_tree> STRUCT
%token <type_tree> RETURN
%token <type_tree> IF
%token <type_tree> ELSE
%token <type_tree> WHILE
%token <type_tree> LCOM
%token <type_tree> RCOM


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%type <type_tree> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag
%type <type_tree> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%%

Program:  ExtDefList {$$=create("Program","",1),add(1,$$,$1);ROOT=$$;}
            ;
ExtDefList:  %empty {$$=NULL;}
            |  ExtDef ExtDefList {$$=create("ExtDefList","",1),add(2,$$,$1,$2);}
             ;
ExtDef: Specifier ExtDecList SEMI {$$=create("ExtDef","",1),add(3,$$,$1,$2,$3);}
            |  Specifier SEMI {$$=create("ExtDef","",1),add(2,$$,$1,$2);}
            |  Specifier FunDec CompSt {$$=create("ExtDef","",1),add(3,$$,$1,$2,$3);}
            |  error FunDec CompSt  {
                    if(misline[@1.first_line-1]==0){
                            misline[@1.first_line-1]=1;
                        mistake++;
                        printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        
                    }
            }
            |  error SEMI  {
                         if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  error RP  {
                   if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  error RC  {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  Specifier error CompSt  {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            |  Specifier ExtDecList   {
                    if(misline[@2.last_line-1]==0){
                                misline[@2.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.last_line);
                        }
            }
             |  Specifier   {
                    if(misline[@1.last_line-1]==0){
                                misline[@1.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.last_line);
                        }
            }
            ;
ExtDecList: VarDec {$$=create("ExtDecList","",1),add(1,$$,$1);}
            |  VarDec COMMA ExtDecList {$$=create("ExtDecList","",1),add(3,$$,$1,$2,$3);}
            ;
Specifier: TYPE {$$=create("Specifier","",1);add(1,$$,$1);}
            |  StructSpecifier {$$=create("Specifier","",1);add(1,$$,$1);}
            ;
StructSpecifier:  STRUCT OptTag LC DefList RC {$$=create("StructSpecifier","",1),add(5,$$,$1,$2,$3,$4,$5);}
            |  STRUCT Tag {$$=create("StructSpecifier","",1),add(2,$$,$1,$2);}
            |  STRUCT  error RC {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            |  error OptTag LC DefList RC {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            ;
OptTag:  %empty {$$=NULL;}
            |  ID {$$=create("OptTag","",1),add(1,$$,$1);}
            ;
Tag:  ID {$$=create("Tag","",1),add(1,$$,$1);}
            ;
VarDec:  ID {$$=create("VarDec","",1),add(1,$$,$1);}
            |  VarDec LB INT RB {$$=create("VarDec","",1),add(4,$$,$1,$2,$3,$4);}
            |  VarDec LB error RB {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            ;
FunDec:  ID LP VarList RP {$$=create("FunDec","",1),add(4,$$,$1,$2,$3,$4);}
            |  ID LP RP {$$=create("FunDec","",1),add(3,$$,$1,$2,$3);}
            |  ID LP error RP  {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            | ID error RP  {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            ;
VarList: ParamDec COMMA VarList {$$=create("VarList","",1),add(3,$$,$1,$2,$3);}
            |  ParamDec {$$=create("VarList","",1),add(1,$$,$1);}
            ;
ParamDec: Specifier VarDec {$$=create("ParamDec","",1),add(2,$$,$1,$2);}
            ;
CompSt:  LC DefList StmtList RC {$$=create("CompSt","",1),add(4,$$,$1,$2,$3,$4);}
            |  LC DefList StmtList{
                    if(misline[@3.last_line-1]==0){
                                misline[@3.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.last_line);
                        }
            }
            |  error RC{
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            ;
StmtList:  %empty {$$=NULL;}
            |  Stmt StmtList {$$=create("StmtList","",1),add(2,$$,$1,$2);}
            ;
Stmt:  Exp SEMI {$$=create("Stmt","",1),add(2,$$,$1,$2);}
            |  CompSt {$$=create("Stmt","",1),add(1,$$,$1);}
            |  RETURN Exp SEMI {$$=create("Stmt","",1),add(3,$$,$1,$2,$3);}
            |  IF LP Exp RP Stmt                %prec LOWER_THAN_ELSE 
                {$$=create("Stmt","",1),add(5,$$,$1,$2,$3,$4,$5);}
            |  IF LP Exp RP Stmt ELSE Stmt {$$=create("Stmt","",1),add(7,$$,$1,$2,$3,$4,$5,$6,$7);}
            |  IF error ELSE Stmt  {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            |  WHILE LP Exp RP Stmt {$$=create("Stmt","",1),add(5,$$,$1,$2,$3,$4,$5);}
            |  WHILE error RP {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            |  WHILE error RC {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            | error SEMI  {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  Exp  {
                    if(misline[@1.last_line-1]==0){
                                misline[@1.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.last_line);
                        }
            }
            |  RETURN Exp   {
                    if(misline[@2.last_line-1]==0){
                                misline[@2.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.last_line);
                        }
            }
            ;
DefList:  %empty {$$=NULL;}
            |  Def DefList {$$=create("DefList","",1),add(2,$$,$1,$2);}
            ;
Def:  Specifier DecList SEMI {$$=create("Def","",1),add(3,$$,$1,$2,$3);}
            |  Specifier error SEMI  {
                    if(misline[@2.first_line-1]==0){
                                misline[@2.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.first_line);
                        }
            }
            |  error DecList SEMI  {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  Specifier DecList {
                    if(misline[@2.last_line-1]==0){
                                misline[@2.last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @2.last_line);
                        }
            }
            ;
DecList:  Dec {$$=create("DecList","",1),add(1,$$,$1);}
            |  Dec COMMA DecList {$$=create("DecList","",1),add(3,$$,$1,$2,$3);}
            ;
Dec:  VarDec {$$=create("Dec","",1),add(1,$$,$1);}
            |  VarDec ASSIGNOP Exp {$$=create("Dec","",1),add(3,$$,$1,$2,$3);}
            ;
Exp:  Exp ASSIGNOP Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp AND Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp OR Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp RELOP Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp PLUS Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp MINUS Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp STAR Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp DIV Exp {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  LP Exp RP {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  MINUS Exp {$$=create("Exp","",1),add(2,$$,$1,$2);}
            |  NOT Exp {$$=create("Exp","",1),add(2,$$,$1,$2);}
            |  ID LP Args RP {$$=create("Exp","",1),add(4,$$,$1,$2,$3,$4);}
            |  ID LP RP {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  Exp LB Exp RB {$$=create("Exp","",1),add(4,$$,$1,$2,$3,$4);}
            |  Exp DOT ID {$$=create("Exp","",1),add(3,$$,$1,$2,$3);}
            |  ID {$$=create("Exp","",1),add(1,$$,$1);}
            |  INT {$$=create("Exp","",1),add(1,$$,$1);}
            |  FLOAT {$$=create("Exp","",1),add(1,$$,$1);}
            |   Exp ASSIGNOP error SEMI  {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  Exp AND error SEMI   {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp OR error SEMI   {
                    if(misline[@1.first_line-1]==0){
                                misline[@1.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @1.first_line);
                        }
            }
            |  Exp RELOP error SEMI   {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp PLUS error SEMI   {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp MINUS error SEMI   {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp STAR error SEMI   {
                   if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp DIV error SEMI   {
                   if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  ID LP error SEMI {
                    if(misline[@3.first_line-1]==0){
                                misline[@3.first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", @3.first_line);
                        }
            }
            |  Exp LB error RB  {
                    if(misline[@3.first_line-1]==0){
                        misline[@3.first_line-1]=1;
                        mistake++;
                        printf("Error Type B at Line %d: wrong expression between \"[\" and \"]\".\n", @3.first_line);
                    }
            }
            ;
Args:  Exp COMMA Args {$$=create("Args","",1),add(3,$$,$1,$2,$3);}
            |  Exp {$$=create("Args","",1),add(1,$$,$1);}
            ;
%%
void yyerror(char* msg)
{
        ;
}