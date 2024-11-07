//n6_42
#include <stdio.h>
#include <stdlib.h>

typedef struct el{
    int data;
    struct el *next;
}el;

el* push(el *top, int data)
{
    el *ptr=malloc(sizeof(el));
    ptr->data=data;
    ptr->next=top;
    return ptr;
}

el* pop(el *top)
{
    if (top==NULL) return top;
    el* cur=top;
    el* precur=top;
    while ((cur->next)!=NULL){
        precur=cur;
        cur=cur->next;
    }
    precur->next=NULL;
    free(cur);
    return top;
}

void printer( el *top)
{
     el* cur=top;
    while (cur!=NULL){
        printf("   %d",cur->data);
        cur=cur->next;
    }
}

int main(void)
{
    el *top=NULL;
    top=push(top,1);
    printer(top);
    top=push(top,2);
    printer(top);
    top=push(top,3);
    printer(top);
    top=push(top,4);
    printer(top);
    top=pop(top);
    printer(top);
    top=pop(top);
    printer(top);
    top=pop(top);
    printer(top);
    top=pop(top);
    return 0;
}