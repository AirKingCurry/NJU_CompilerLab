#include"SymbolTable.h"
#include<stdio.h>
#include<stdlib.h>
HashNode SymbolTable[HASHTABLESIZE];
const HashNode check(char *name,int judge)
//0表示非函数，1表示函数
{
    unsigned int val=0,i;
    char* tempname=name;
    strcpy(tempname,name);
    for(;*tempname;++tempname)
    {
        val=(val<<2)+*tempname;
        i=val&~(HASHTABLESIZE-1);
        if(i!=0)
            val=(val^(i>>12))&(HASHTABLESIZE-1);
    }
    HashNode temp=SymbolTable[val];
    while(temp!=NULL)
    {
        //printf("I'm here! And my name is %s, your name is %s\n",temp->name,name);
        if(strcmp(temp->name,name)==0)
        {
            if(judge==1&&temp->val->kind==FUNCTION)
            //成功找到了函数
            {
                return temp;
            }
            else if(judge==0&&temp->val->kind!=FUNCTION)
            {
                return temp;
            }
        }
        temp=temp->next;
    }
    return temp;
}
void insertnode(HashNode temp)
{
    unsigned int val=0,i;
    char* name=(char*)malloc(sizeof(char)*32);
    strcpy(name,temp->name);
    for(;*name;++name)
    {
        val=(val<<2)+*name;
        if(i=val&~(HASHTABLESIZE-1))
        val=(val^(i>>12))&(HASHTABLESIZE-1);
    }
    temp->next=SymbolTable[val];
    SymbolTable[val]=temp;
}