#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6

typedef struct tnode {
    char *data;
    struct tnode *next;
} tnode;

typedef tnode *ptr;

void addnode(ptr *a, char *val)
{
    ptr new=(ptr)malloc(sizeof(tnode));
    new->data=val;
    new->next=*a;
    *a=new;
}

void printer(ptr *a)
{
    ptr cur=*a;
    while (cur!=NULL){
        printf("   %s",(*cur).data);
        cur=cur->next;
    }
    printf("\n");
}

int twin(char *n,ptr *a)
{
    ptr cur=*a;
    if (cur==NULL) return 0;
    while (cur!=NULL){
        if (strcmp((cur->data),n)==0) return 1;
        cur=cur->next;
    }
}

void createl3(ptr *l1,ptr *l2)
{
    ptr l3=NULL;
    ptr cur1=*l1;
    ptr cur2=*l2;
    int f=0;
    while (cur1!=NULL){
        f=twin((cur1->data),l2);
        //printf("   %d",f);
        if (f==0){
            char *temp=(cur1->data);
            addnode(&l3,temp);
            //printf("   %d",temp);
        }
        cur1=cur1->next;
    }
    while (cur2!=NULL){
        f=twin(cur2->data,l1);
        if (f==0){
            char *temp=(cur2->data);
            addnode(&l3,temp);
            //printf("   %d",temp);
        }
        cur2=cur2->next;
    }
    //if (l3==NULL) return;
    printer(&l3);
    return;
}

int main(void)
{
    ptr ptr_s1=NULL;
    ptr ptr_s2=NULL;
    int i=SIZE;
    int j=SIZE;
    char* mas[SIZE]={"abc","def","ghi","jkl","mno","pqr"};
    while (i>0){
        addnode(&ptr_s1,mas[SIZE-i]);
        i--;
    }
    char* ar[SIZE]={"abc","def","ihg","lkj","onm","rqp"};
    while (j>0){
        addnode(&ptr_s2,ar[SIZE-j]);
        j--;
    }
    printer(&ptr_s1);
    printer(&ptr_s2);
    createl3(&ptr_s1,&ptr_s2);
    return 0;
}