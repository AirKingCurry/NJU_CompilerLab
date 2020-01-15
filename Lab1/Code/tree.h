#ifndef _TREE_H_
#define _TREE_H_

typedef struct TREE
{
    char name[32];
    char text[32];
    int childnum;
   //struct TREE *parent;
    struct TREE *child[20];
    int line;
    int flag;
}Tree;

Tree* create(char *name,char *s,int flag);

void add(int chilenum,Tree* parent,...);

void Treeprint(Tree* root,int count);

Tree * ROOT;

#endif