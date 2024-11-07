//n6_32

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    double f;
    char *s[2];
}data;

typedef struct inode {
    struct data *p;
    struct inode *next;
} inode;

typedef data *ptr1;
typedef inode *ptr2;

ptr2 copybuild(ptr2 l1)
{
    if (l1==NULL) return NULL;
    ptr2 new=(ptr2)malloc(sizeof(inode));
    new->p=(ptr1)malloc(sizeof(data));
    new->p->f=l1->p->f;
    for (int i = 0; i < 2; i++)
    {
        new->p->s[i] = (char*)malloc(strlen(l1->p->s[i]) + 1); 
        strcpy(new->p->s[i], l1->p->s[i]);
    }
    new->next = copybuild(l1->next);
    return new;
}


void printer(ptr2 l)
{
    while (l!=NULL)
    {
        printf("   %f",l->p->f);
        printf("   %s,   %s",l->p->s[0],l->p->s[1]);
        printf("\n");
        l=l->next;
    }
    return;
}

int main(void)
{ 
    ptr2 l1=(ptr2)malloc(sizeof(inode));
    l1->p=(ptr1)malloc(sizeof(data));
    l1->p->f=1.0;
    //char s01[3]="abc";
    //char s02[3]="def";
    //char s11[3]="123";
    //char s12[3]="456";
    l1->p->s[0]="abc";
    l1->p->s[1]="def";
    ptr2 l11=(ptr2)malloc(sizeof(inode));
    l11->p=(ptr1)malloc(sizeof(data));
    l11->p->f=2.0;
    l11->p->s[0]="abc";
    l11->p->s[1]="def";
    l1->next=l11;
    l11->next=NULL;
    ptr2 l2=copybuild(l1);
    printer(l1);
    printer(l2);
    return 0;
}