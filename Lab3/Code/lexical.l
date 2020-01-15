%option yylineno
%{
    #include "syntax.tab.h"
    #include<string.h>
    #include"tree.h"
    int yycolumn=1;
    //extern Tree* create(char *name,char *s);
    extern int mistake;
    #define YY_USER_ACTION \
        yylloc.first_line=yylineno;\
        yylloc.last_line=yylineno;\
        yylloc.first_column=yycolumn;\
        yylloc.last_column=yylloc.first_column+yyleng-1;\
        yycolumn+=yyleng;
%}
digit  [0-9]
digits [0-9]+
letter [a-zA-Z]
STRUCT struct
RELOP  >|<|>=|<=|==|!=


%%
0|[1-9]{digit}*  {yylval.type_tree=create("INT",yytext,0);return INT;}//INT
{digits}\.{digits}  {yylval.type_tree=create("FLOAT",yytext,0);return FLOAT;}//FLOAT     
{STRUCT}   {yylval.type_tree=create("STRUCT","",0);return STRUCT;}
"int"|"float"   {yylval.type_tree=create("TYPE",yytext,0); return TYPE;}
\(   {yylval.type_tree=create("LP","",0);return LP;}
\)   {yylval.type_tree=create("RP","",0);return RP;}
\[   {yylval.type_tree=create("LB","",0);return LB;}
\]   {yylval.type_tree=create("RB","",0);return RB;}
\{   {yylval.type_tree=create("LC","",0);return LC;}
\}   {yylval.type_tree=create("RC","",0);return RC;}
return   {yylval.type_tree=create("RETURN","",0);return RETURN;}
if   {yylval.type_tree=create("IF","",0);return IF;}
else   {yylval.type_tree=create("ELSE","",0);return ELSE;}
while   {yylval.type_tree=create("WHILE","",0);return WHILE;}
[_a-zA-Z][_0-9a-zA-Z]*  {yylval.type_tree=create("ID",yytext,0); return ID;}//ID
;   {yylval.type_tree=create("SEMI","",0);return SEMI;}//;
,   {yylval.type_tree=create("COMMA","",0);return COMMA;}//,
=   {yylval.type_tree=create("ASSIGNOP","",0);return ASSIGNOP;}//=
{RELOP}   {yylval.type_tree=create("RELOP",yytext,0);; return RELOP;}
\+   {yylval.type_tree=create("PLUS","",0);return PLUS;}
-   {yylval.type_tree=create("MINUS","",0);return MINUS;}
\*   {yylval.type_tree=create("STAR","",0);return STAR;}
\/   {yylval.type_tree=create("DIV","",0);return DIV;}
"/*"    {
            //printf("the line is %d\n",yylineno);
            int line=yylineno;
            char c=input();
            int flag=0;
            while(c!=0)
            {
                if(flag==1)
                {
                    if(c=='/'){
                        flag=2;
                        break;
                    }
                    else{
                        if(c!='*')
                            flag=0;
                    }
                }
                else{
                    if(c=='*')
                        flag=1;
                }
                c=input();
            }
            //printf("the line is %d\n",yylineno);
            if(flag!=2){
                mistake++;
                printf("Error Type B at Line %d: The \/\* can not match a \*\/.\n",line);
            }
        }  
"*/" { mistake++;printf("hahaError Type B at Line %d: syntax error.\n", yylineno);}
\/\/ { char c=input();
            while(c!='\n')
            c=input();
            }

&&   {yylval.type_tree=create("AND","",0);return AND;}
"||"   {yylval.type_tree=create("OR","",0);return OR;}
\.   {yylval.type_tree=create("DOT","",0);return DOT;}
!   {yylval.type_tree=create("NOT","",0);return NOT;}
\r  {;}
\n {yycolumn=1;}
" "|\t  {;}
.   {mistake++;printf("Error type A at Line %d: Mysterious characters \'%s'\n",yylineno,yytext);}

%%