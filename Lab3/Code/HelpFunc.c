#include"SemanticAnalysis.h"
#include"SymbolTable.h"
#include"HelpFunc.h"
#include<stdio.h>
#include<stdlib.h>
int string_to_int(char* temp)
{
    int ans=0;
    while((char)(*temp)!='\0')
    {
        ans=ans*10+(int)((char)(*temp)-'0');
        temp++;
    }
    return ans;
}
Type mycopy_type(Type temp)
{
    Type ans=(Type) malloc(sizeof(struct Type_));
    ans->kind=temp->kind;
    if(temp->kind==BASIC)
    {
        ans->u.basic=temp->u.basic;
    }
    else if(temp->kind==ARRAY)
    {
        ans->u.array.size=temp->u.array.size;
        ans->u.array.elem=mycopy_type(temp->u.array.elem);
    }
    else if(temp->kind==STRUCTURE)
    {
        ans->u.structure=mycopy_structure(temp->u.structure);
    }
    else if(temp->kind==FUNCTION)
    {
        ans->u.myfunc=mycopy_func(temp->u.myfunc);
    }
 /*   else
    {
        ans->u.Struct_Name=(char*)malloc(sizeof(char)*32);
        strcpy(ans->u.Struct_Name,temp->u.Struct_Name);
    }*/
    return ans;
}
FieldList mycopy_structure(FieldList temp)
{
    FieldList ans=(FieldList)malloc(sizeof(struct FieldList_));
    //ans->name=(char*) malloc(sizeof(temp->name)+2);
    strcpy(ans->name,temp->name);
    ans->type=mycopy_type(temp->type);
    if(temp->next!=NULL)
    {
        ans->next=mycopy_structure(temp->next);
    }
    else ans->next=NULL;
    return ans;
}
FuncList mycopy_func(FuncList temp)
{
    FuncList ans=(FuncList)malloc(sizeof(struct FuncList_));
    //ans->name=(char*) malloc(sizeof(temp->name)+2);
    strcpy(ans->name,temp->name);
    ans->type=mycopy_type(temp->type);
    if(temp->next!=NULL)
    {
        ans->next=mycopy_func(temp->next);
    }
    else ans->next=NULL;
    return ans;
}



void output_type(Type temp)
{
    if(temp->kind==BASIC)
    {
        printf("BASIC:");
        if(temp->u.basic==TYPE_INT)
        printf("int\n");
        else printf("float\n");
    }
    else if(temp->kind==ARRAY)
    {
        printf("ARRAY:");
        printf("size:%d",temp->u.array.size);
        output_type(temp->u.array.elem);
    }
    else if(temp->kind==STRUCTURE)
    {
        printf("STRUCTURE:");
        output_fieldlist(temp->u.structure);
    }
    else if(temp->kind==FUNCTION)
    {
        printf("FUNCTION:");
        output_func(temp->u.myfunc);
    }
}
void output_fieldlist(FieldList temp)
{
    if(temp!=NULL)
    {
        printf("name:%s",temp->name);
        output_type(temp->type);
        output_fieldlist(temp->next);
    }
}
void output_func(FuncList temp)
{
    if(temp!=NULL)
    {
        printf("name:%s",temp->name);
        output_type(temp->type);
        output_func(temp->next);
    }
}
int isTypeEqual(Type a,Type b)
{
    if(a->kind!=b->kind)
        return 0;
    else
    {
        if(a->kind==BASIC)
        {
            if(a->u.basic==b->u.basic)
            return 1;
            else return 0;
        }
        else if(a->kind==ARRAY)
        {
            if(isTypeEqual(a->u.array.elem,b->u.array.elem)==1)
            {
                return 1;
            }
            else return 0;
        }
        else if(a->kind==STRUCTURE)
        {
            if(IsStructureEqual(a->u.structure,b->u.structure)==1)
                return 1;
            else return 0;
        }
        else if(a->kind==FUNCTION)
        {
            if(IsFuncEqual(a->u.myfunc,a->u.myfunc)==1)
                return 1;
            else return 0;
        }
        else return 0;
    }
    
}
/*
int IsStructureEqual(FieldList a,FieldList b)
{
    while(a!=NULL&&b!=NULL){
        if(isTypeEqual(a->type,b->type)==1){
            a=a->next;
            b=b->next;
        }
        else{
            return 0;
        }
    }
    if(a==NULL&&b==NULL)
        return 1;
    return 0;
}
int IsFuncEqual(FuncList a,FuncList b)
{
    if(strcmp(a->name,b->name)==0&&isTypeEqual(a->type,b->type)==1)
    return 1;
    else return 0;
}*/
int IsStructureEqual(FieldList a,FieldList b)
{
    if((a==NULL)&&(b==NULL))
        return 1;
    else if(a==NULL||b==NULL)
        return 0;
    if(isTypeEqual(a->type,b->type)==1&&IsStructureEqual(a->next,b->next)==1)
        return 1;
    else return 0;
}
int IsFuncEqual(FuncList a,FuncList b)
{
    if((a==NULL)&&(b==NULL))
        return 1;
    else if(a==NULL||b==NULL)
        return 0;
    if(strcmp(a->name,b->name)==0&&isTypeEqual(a->type,b->type)==1)
        return IsFuncEqual(a->next,b->next);
    else return 0;
}