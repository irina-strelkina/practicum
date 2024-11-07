//n6_43
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
    el *ptr=top->next;
    free(top);
    return ptr;
}

void printer(const el *top)
{
    const el* cur=top;
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