//number 6.28
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct tnode {
    int data;
    struct tnode *next;
} tnode;

typedef tnode *ptr;

void chng(ptr *a)
{
    ptr cur=*a;
    ptr precur=*a;
    if (cur==NULL || cur-> next == NULL)
        return;
    while (precur->next->next!=NULL){
        precur=precur->next;
    } 
    cur=precur->next;
    cur->next=(*a)->next;
    (*a)->next=NULL;
    precur->next=*a;
    *a=cur;
}

void printer(ptr *a)
{
    ptr cur=*a;
    while (cur!=NULL){
        printf("   %d",(*cur).data);
        cur=cur->next;
    }
    printf("\n");
}

void addnode(ptr *a, int val)
{
    ptr new=(ptr)malloc(sizeof(tnode));
    new->data=val;
    new->next=*a;
    *a=new;
}

void delel1(ptr *a, int val)
{
    ptr cur=*a;
    if (cur==NULL) return;
    while (cur!=NULL && (cur->next->data)!=val) cur=cur->next;
    if (cur==NULL) return;
    ptr d=cur;
    d=d->next;
    cur->next=cur->next->next;
    free(d);
    return;
}

void delel2(ptr *a,int val)
{
    ptr cur=*a;
    if (cur==NULL) return;
    if ((cur->data)==val){
        *a=(*a)->next;
        free(cur);
        return;
    }
    delel1(a,val);
}

void dup(ptr *a, int val)
{
    ptr cur=*a;
    ptr postcur=*a;
    if (cur==NULL) return;
    while (cur!=NULL && (cur->data)!=val) cur=cur->next;
    if (cur==NULL) return;
    postcur=(ptr)malloc(sizeof(tnode));
    postcur->data=val;
    postcur->next=cur->next;
    cur->next=postcur;
}

int main(void)
{
    ptr ptr_s=NULL;
    int i=SIZE;
    int mas[SIZE]={1,2,3,4,6,6,7,8};
    
    while (i>0){
        addnode(&ptr_s,mas[SIZE-i]);
        i--;
    }
    printer(&ptr_s);
    chng(&ptr_s);
    printer(&ptr_s);
    delel1(&ptr_s,mas[3]);
    printer(&ptr_s);
    delel2(&ptr_s,mas[0]);
    printer(&ptr_s);
    /*delel1(&ptr_s,mas[4]);
    printer(&ptr_s);*/
    dup(&ptr_s,mas[5]);
    printer(&ptr_s);
    return 0;
}
