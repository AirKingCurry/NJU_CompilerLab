#include<stdio.h>
#include"syntax.tab.h"
#include"tree.h"
#include"SemanticAnalysis.h"
#include"HelpFunc.h"
extern HashNode SymbolTable[HASHTABLESIZE];
int mistake=0;
extern Tree* ROOT;
extern void yyrestart  (FILE * input_file );
extern int yyparse (void);
int main(int argc,char** argv)
{
    for(int i=0;i<HASHTABLESIZE;i++){
        SymbolTable[i]=NULL;
    }
    if(argc<=1)
        return 1;
    FILE* f=fopen(argv[1],"r");
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
    return 0;
}