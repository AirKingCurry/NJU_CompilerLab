#ifndef _TREE_H_
#define _TREE_H_
//extern struct Type_;

typedef struct TREE
{
    char name[32];
    char text[32];
    int childnum;
   //struct TREE *parent;
    struct TREE *child[20];
    //struct Type_ type;
    int line;
    int flag;

    enum{left,right,undefined} expr;//左值还是右值表达式
}Tree;

Tree* create(char *name,char *s,int flag);

void add(int chilenum,Tree* node,...);

void Treeprint(Tree* root,int count);

Tree * ROOT;

#endif