#include<stdio.h>
#include"tree.h"
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
extern int yylineno;
Tree* create(char *name,char *s,int flag)
{
    Tree* newtree=(Tree*)malloc(sizeof(struct TREE));
    //newtree->parent=NULL;
    for(int i=0;i<20;i++)
        newtree->child[i]=NULL;
    newtree->line=yylineno;
    newtree->childnum=0;
    strcpy(newtree->text,s);
    strcpy(newtree->name,name);
    newtree->flag=flag;
    //printf("%slala\n\n",newtree->name);
    return newtree;
}
void add(int childnum,Tree* parent,...)
{
    //printf("hatua\n");
    /*printf("%d\n",parent->line);
    for(int i=0;i<3;i++)
        printf("%c\n",parent->name[i]);*/
    va_list ptr;
    
    va_start(ptr,parent);
    
    for(int i=0;i<childnum;i++)
    {
        Tree *cnode; 
        cnode=va_arg(ptr,Tree*);
        parent->child[i]=cnode;
        //printf("haha  %d\n",childnum);
        //cnode->parent=parent;
    }
    //printf("love\n");
    parent->line=parent->child[0]->line;
    parent->childnum=childnum;
    va_end(ptr);
} 
void Treeprint(Tree* root,int count)
{
    if(root!=NULL){
        for(int i=0;i<count;i++)
            printf("  ");
        printf("%s",root->name);
        if(root->flag==0){
            if(strcmp(root->name,"ID")==0)
                printf(": %s",root->text);
            else if(strcmp(root->name,"TYPE")==0)
                printf(": %s",root->text);
            else if(strcmp(root->name,"INT")==0)
                printf(": %d",atoi(root->text));   
            else if(strcmp(root->name,"FLOAT")==0)
                printf(": %f",atof(root->text));
        }
        else
            printf(" (%d)",root->line);
        printf("\n");
        //printf("%d\n",root->childnum);
        for(int i=0;i<root->childnum;i++)
            Treeprint(root->child[i],count+1);
    }
}