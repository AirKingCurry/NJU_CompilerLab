#include"ObjectCode.h"
#include<stdio.h>
#include"syntax.tab.h"
#include"tree.h"
#include"SemanticAnalysis.h"
#include"HelpFunc.h"
#include"Intercode.h"
#include"SymbolTable.h"
#include<stdlib.h>
extern Var objcode_head;
int local_offset;
FILE* file;

void Trans_final(InterCode head,char *filename)
{
    //printf("haha  %s\n",filename);
    file=fopen(filename,"w+");
    //if(!file)
       // printf("lala\n");
    
    init_final();
    
    init_regs();
    //printf("lala\n");
    local_offset=0;
    while(head!=NULL){
        //printInter(head);
        InterCode next=next_firstintr(head);
        while(head!=next){
            if(head->kind==W_LABEL){
                Trans_final_Label(head);
            }
            else if(head->kind==W_ASSIGN)
            {
                Trans_final_ASSIGN(head);
            }
            else if(head->kind==W_ADD){
                Trans_final_ADD(head);
            }
            else if(head->kind==W_SUB){
                Trans_final_SUB(head);
            }
            else if(head->kind==W_MUL){
                Trans_final_MUL(head);
            }
            else if(head->kind==W_DIV){
                Trans_final_DIV(head);
            }
            else if(head->kind==W_GOTO){
                Trans_final_GOTO(head);
            }
            else if(head->kind==W_CALL||head->kind==W_ARG){
                Trans_final_ARG_CALL(head);
                while(head->kind!=W_CALL)
                    head=head->next;
            }
            else if(head->kind==W_RETURN){
                Trans_final_RETURN(head);
            }
            else if(head->kind==W_IFGOTO){
                Trans_final_IFGOTO(head);
            }
            else if(head->kind==W_FUNCTION){
                Trans_final_FUNCTION(head);
            }
            //else if 
            else if(head->kind==W_READ){
                Trans_final_READ(head);
            }
            else if(head->kind==W_WRITE){
                Trans_final_WRITE(head);
            }
            else if(head->kind==W_DEC)
            {
                ;
            }
            head=head->next;
        }
    }
    fclose(file);
}

void Trans_final_READ(InterCode head){
    fprintf(file,"addi $sp, $sp, -4\n");
    fprintf(file,"sw $ra, 0($sp)\n");
    fprintf(file,"jal read\n");
    fprintf(file,"lw $ra, 0($sp)\n");
    fprintf(file,"addi $sp, $sp, 4\n");
    int reg=get_regs(head->u.Single.op);
    fprintf(file,"move %s, $v0\n",regs[reg].name);
    Load_Memory(reg);
}
 void Trans_final_WRITE(InterCode head){
    //Var to_be_written=check_var(head->u.Single.op);
    int reg=get_regs(head->u.Single.op);
    fprintf(file,"move $a0, %s\n",regs[reg].name);
    fprintf(file,"addi $sp, $sp, -4\n");
    fprintf(file,"sw $ra, 0($sp)\n");
    fprintf(file,"jal write\n");
    fprintf(file,"lw $ra, 0($sp)\n");
    fprintf(file,"addi $sp, $sp, 4\n");
    for(int i=8;i<16;i++){
        if(regs[i].free==1)
            regs[i].free=0;
    }
}
void Trans_final_Label(InterCode head){
    fprintf(file,"%s:\n",head->u.Single.op->u.value);
}
void Trans_final_ADD(InterCode head){
    
    if(head->u.Double.result->kind!=MYSTAR){
        int res=get_regs(head->u.Double.result);
        int op1=get_regs(head->u.Double.op1);
        int op2=get_regs(head->u.Double.op2);
        fprintf(file,"add %s, %s, %s\n",regs[res].name,regs[op1].name,regs[op2].name);
        Load_Memory(res);
    }
    else{
        printf("The add exp's left is MYSTAR!\n");
    }
}
void Trans_final_SUB(InterCode head){
    if(head->u.Double.result->kind!=MYSTAR){
        int res=get_regs(head->u.Double.result);
        int op1=get_regs(head->u.Double.op1);
        int op2=get_regs(head->u.Double.op2);
        fprintf(file,"sub %s, %s, %s\n",regs[res].name,regs[op1].name,regs[op2].name);
        Load_Memory(res);
    }
    else{
        printf("The sub exp's left is MYSTAR!\n");
    }
}
void Trans_final_MUL(InterCode head){
    if(head->u.Double.result->kind!=MYSTAR){
        int res=get_regs(head->u.Double.result);
        int op1=get_regs(head->u.Double.op1);
        int op2=get_regs(head->u.Double.op2);
        fprintf(file,"mul %s, %s, %s\n",regs[res].name,regs[op1].name,regs[op2].name);
        Load_Memory(res);
    }
    else{
        printf("The mul exp's left is MYSTAR!\n");
    }
}
void Trans_final_DIV(InterCode head){
    if(head->u.Double.result->kind!=MYSTAR){
        int res=get_regs(head->u.Double.result);
        int op1=get_regs(head->u.Double.op1);
        int op2=get_regs(head->u.Double.op2);
        fprintf(file,"div %s, %s, %s\n",regs[res].name,regs[op1].name,regs[op2].name);
        Load_Memory(res);
    }
    else{
        printf("The div exp's left is MYSTAR!\n");
    }
}
void Trans_final_ASSIGN(InterCode head){
    int right=get_regs(head->u.Assign.right);
    if(head->u.Assign.left->kind!=MYSTAR){
        int left=get_regs(head->u.Assign.left);
        fprintf(file,"move %s, %s\n",regs[left].name,regs[right].name);
        Load_Memory(left);
    }
    else{
        Var left=check_var(head->u.Assign.left);
        int free=find_freereg();
        regs[free].free=1;
        fprintf(file,"lw %s, %d($fp)\n",regs[free].name,left->offset);
        fprintf(file,"sw %s, 0(%s)\n",regs[right].name,regs[free].name);
        regs[free].free=0;
        regs[right].free=0;
    }
}
void Trans_final_GOTO(InterCode head){
    fprintf(file,"j %s\n",head->u.Single.op->u.value);
}
void Trans_final_ARG_CALL(InterCode head)
{
    int num=0;
    if(head->kind==W_ARG)
    {
        while(head->kind==W_ARG)
        {
            num++;
            //local_offset+=4;
            fprintf(file,"addi $sp, $sp, -4\n");
            int free=get_regs(head->u.Single.op);
            fprintf(file,"sw %s, 0($sp)\n",regs[free].name);
            head=head->next;
            regs[free].free=0;
        }
    }
    Operand x=head->u.Assign.left;
    Operand y=head->u.Assign.right;
    fprintf(file,"jal %s\n",y->u.value);
    fprintf(file,"addi $sp, $sp, %d\n",num*4);
    int index1=get_regs(x);
    fprintf(file,"move %s, $v0\n",regs[index1].name);
    Load_Memory(index1);
}

void Trans_final_RETURN(InterCode head){
    fprintf(file,"lw $ra, 4($fp)\n");
    fprintf(file,"addi $sp, $fp, 8\n");
    int free=get_regs(head->u.Single.op);
    //RETURN x
    fprintf(file,"lw $fp, 0($fp)\n");
    fprintf(file,"move $v0, %s\n",regs[free].name);
    fprintf(file,"jr $ra\n");
    for(int i=8;i<16;i++){
        if(regs[i].free==1)
            regs[i].free=0;
    }
}
void Trans_final_IFGOTO(InterCode head){
    Operand x=head->u.Three.x;
    Operand y=head->u.Three.y;
    Operand label=head->u.Three.label;
    char relop[32];
    strcpy(relop,head->u.Three.relop);
    int index1=0;
    int index2=0;
    index1=get_regs(x);
    index2=get_regs(y);
    if(strcmp(relop,"==")==0)
    {
            fprintf(file,"beq %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    else if(strcmp(relop,"!=")==0)
    {
            fprintf(file,"bne %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    else if(strcmp(relop,">")==0)
    {
            fprintf(file,"bgt %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    else if(strcmp(relop,"<")==0)
    {
            fprintf(file,"blt %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    else if(strcmp(relop,">=")==0)
    {
            fprintf(file,"bge %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    else if(strcmp(relop,"<=")==0)
    {
            fprintf(file,"ble %s, %s, %s\n",regs[index1].name,regs[index2].name,label->u.value);
    }
    regs[index1].free=0;
    regs[index2].free=0;
}
/*void Trans_final_Dec(InterCode head){
    fprintf(file,"addi $sp, $sp, %d\n",-head->u.Dec.size);
    local_offset+=head->u.Dec.size;
    Var array=(Var)malloc(sizeof(struct Var_));
    strcpy(array->name,head->u.Dec.op->u.value);
    array->offset=(-1)*local_offset;
    insert_newvar(array);
}*/
void Trans_final_FUNCTION(InterCode head){
    fprintf(file,"\n%s:\n",head->u.Single.op->u.value);
    fprintf(file,"addi $sp, $sp, -8\n");
    fprintf(file,"sw $fp, 0($sp)\n");
    fprintf(file,"sw $ra, 4($sp)\n");
    fprintf(file,"move $fp, $sp\n");
    local_offset=0;
    int count=0;
    head=head->next;
    while(head->kind==W_PARAM){
        Var param=(Var)malloc(sizeof(struct Var_));
        strcpy(param->name,head->u.Single.op->u.value);
        param->offset=8+count*4;
        insert_newvar(param);
        count++;
        head=head->next;
    }
    InterCode cur=head;
    //cur=cur->next;
    while(cur!=NULL&&cur->kind!=W_FUNCTION){
        if(cur->kind==W_ASSIGN){
            sub_sp(cur->u.Assign.left);
            sub_sp(cur->u.Assign.right);
        }
        else if(cur->kind==W_ADD||cur->kind==W_SUB||cur->kind==W_MUL||cur->kind==W_DIV){
            sub_sp(cur->u.Double.op1);
            sub_sp(cur->u.Double.op2);
            sub_sp(cur->u.Double.result);
        }
        else if(cur->kind==W_DEC){
            local_offset+=cur->u.Dec.size;
            Var array=(Var)malloc(sizeof(struct Var_));
            strcpy(array->name,cur->u.Dec.op->u.value);
            array->offset=(-1)*local_offset;
            insert_newvar(array);
        }
        else if(cur->kind==W_CALL){
            sub_sp(cur->u.Assign.left);
        }
        else if(cur->kind==W_ARG)
        {
            sub_sp(cur->u.Single.op);
        }
        else if(cur->kind==W_IFGOTO){
            sub_sp(cur->u.Three.x);
            sub_sp(cur->u.Three.y);
        }
        else if(cur->kind==W_WRITE){
            sub_sp(cur->u.Single.op);
        }
        else if(cur->kind==W_READ){
            sub_sp(cur->u.Single.op);
        }
        cur=cur->next;
    }
    fprintf(file,"addi $sp, $sp, %d\n",(-1)*local_offset);
    for(int i=8;i<16;i++){
        if(regs[i].free==1)
            regs[i].free=0;
    }
}

void sub_sp(Operand x){
    if(x->kind==CONSTANT||x->kind==VAR_CONS)
    {
        return ;
    }
    Var temp=check_var(x);
    if(temp==NULL)//第一次出现这个变量，需要新建一个varlist，并且插入链表中
    {
        local_offset+=4;
        Var new_var=(Var)malloc(sizeof(struct Var_));
        strcpy(new_var->name,x->u.value);
        new_var->next=NULL;
        new_var->offset=-local_offset;
        insert_newvar(new_var);
    }
}
void init_regs()
{
    strcpy(regs[0].name,"$zero");
    strcpy(regs[1].name,"$at");
    strcpy(regs[2].name,"$v0");
    strcpy(regs[3].name,"$v1");
    strcpy(regs[4].name,"$a0");
    strcpy(regs[5].name,"$a1");
    strcpy(regs[6].name,"$a2");
    strcpy(regs[7].name,"$a3");
    strcpy(regs[8].name,"$t0");
    strcpy(regs[9].name,"$t1");
    strcpy(regs[10].name,"$t2");
    strcpy(regs[11].name,"$t3");
    strcpy(regs[12].name,"$t4");
    strcpy(regs[13].name,"$t5");
    strcpy(regs[14].name,"$t6");
    strcpy(regs[15].name,"$t7");
    strcpy(regs[16].name,"$s0");
    strcpy(regs[17].name,"$s1");
    strcpy(regs[18].name,"$s2");
    strcpy(regs[19].name,"$s3");
    strcpy(regs[20].name,"$s4");
    strcpy(regs[21].name,"$s5");
    strcpy(regs[22].name,"$s6");
    strcpy(regs[23].name,"$s7");
    strcpy(regs[24].name,"$t8");
    strcpy(regs[25].name,"$t9");
    strcpy(regs[26].name,"$k0");
    strcpy(regs[27].name,"$k1");
    strcpy(regs[28].name,"$gp");
    strcpy(regs[29].name,"$sp");
    strcpy(regs[30].name,"$fp");
    strcpy(regs[31].name,"$ra");
    for(int i=0;i<32;i++)
    {
        regs[i].free=0;
        regs[i].variables=NULL;
    }
}
int get_regs(Operand x)
{
    if(x->kind==CONSTANT||x->kind==VAR_CONS)
    {
        int j;
        for(j=8;j<=15;j++)
        {
            if(regs[j].free==0)
            {
                regs[j].free=1;
                regs[j].variables=NULL;
                fprintf(file,"li %s, %d\n",regs[j].name,x->u.var_no);
                return j;
            }
        }
    }
    int i;
    for(i=8;i<=15;i++)
    {
        if(regs[i].free==0)
        {
            regs[i].free=1;
            Var temp=check_var(x);
            temp->reg=i;
            regs[i].variables=temp;
            //如果变量是&x类型的
            if(x->kind==TEMP_ADDR||x->kind==VAR_ADDR)
            {
                fprintf(file,"addi %s, $fp, %d\n",regs[i].name,temp->offset);
            }
            //如果变量是*x类型的
            else if(x->kind==MYSTAR)
            {
                fprintf(file,"lw %s, %d($fp)\n",regs[i].name,temp->offset);
                fprintf(file,"lw %s, 0(%s)\n",regs[i].name,regs[i].name);
            }
            else
            {
                fprintf(file,"lw %s, %d($fp)\n",regs[i].name,temp->offset);
            }
            break;
        } 
    }
    if(i==16){
        printf("There is no freereg left!\n");
        abort();
    }
    return i;
}
Var check_var(Operand x)
{
    if(x->kind==CONSTANT||x->kind==VAR_CONS){
        abort();
    }
    Var cur=objcode_head;
    Var ans=NULL;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,x->u.value)==0)
        {
            ans=cur;
            break;
        }
        cur=cur->next;
    }
    return ans;
}
void Load_Memory(int reg){
    int offset=regs[reg].variables->offset;
    fprintf(file,"sw %s, %d($fp)\n",regs[reg].name,offset);
    //Free the regs
    for(int i=8;i<16;i++){
        if(regs[i].free==1)
            regs[i].free=0;
    }
}
void init_final(){
    fprintf(file,".data\n");
    fprintf(file,"_prompt: .asciiz \"Enter an integer:\"\n");
    fprintf(file,"_ret: .asciiz \"\\n\"\n");
    fprintf(file,".globl main\n");
    fprintf(file,".text\n");
    fprintf(file,"read:\n");
    fprintf(file,"li $v0, 4\n");
    fprintf(file,"la $a0, _prompt\n");
    fprintf(file,"syscall\n");
    fprintf(file,"li $v0, 5\n");
    fprintf(file,"syscall\n");
    fprintf(file,"jr $ra\n");

    fprintf(file,"\n");
    fprintf(file,"write:\n");
    fprintf(file,"li $v0, 1\n");
    fprintf(file,"syscall\n");
    fprintf(file,"li $v0, 4\n");
    fprintf(file,"la $a0, _ret\n");
    fprintf(file,"syscall\n");
    fprintf(file,"move $v0, $0\n");
    fprintf(file,"jr $ra\n\n");
}
void insert_newvar(Var temp)
{
    temp->next=objcode_head;
    objcode_head=temp;
}
int find_freereg()
{
    for(int i=8;i<=15;i++)
    {
        if(regs[i].free==0)
        {
            return i;
        }
    }
    printf("There is no freereg left!\n");
    abort();
}