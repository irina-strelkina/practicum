//n6_45e
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
}streenode;

typedef streenode* tnode;

typedef struct el{
    tnode data;
    struct el *next;
}el;

el* push(el *top, tnode data)
{
    el *ptr=malloc(sizeof(el));
    ptr->data=data;
    ptr->next=top;
    return ptr;
}

el* getpreel(el *top)
{
    el* ptr=top;
    while ((ptr->next->next)!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr;
}

el* getel(el *top)
{
    el* ptr=top;
    while ((ptr->next)!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr;
}

/*el* pop(el *top)
{
    if (top==NULL) return top;
    el *ptr=top->next;
    free(top);
    return ptr;
}*/

el* pop(el *top)
{
    if (top==NULL) return top;
    el *ptr1=getpreel(top);
    el *ptr2=getel(top);
    ptr1->next=NULL;
    free(ptr2);
    return top;
}

void makenode( tnode *root, int val)
{
    //tnode *cur=root;
    if (*root==NULL){
        tnode new=(tnode)malloc(sizeof(streenode));
        new->data=val;
        new->left=NULL;
        new->right=NULL;
        *root=new;
        return;
    }
    if (((*root)->data)>=val){
        makenode (&((*root)->left),val);
    }
    else{
        makenode (&((*root)->right),val);
    }
    
}

/*void cleartree(tnode *root)
{
    tnode cur=*root;
    if (cur == NULL){
        return;
    }
    cleartree(&(cur -> left));
    cleartree(&(cur -> right));
    free(cur);
}*/


int count_ties(tnode root, int level)
{
    tnode tree=root;
    int now=1;
    int total=0;
    int res=0;
    if (tree==NULL) return 0;
    el* q=NULL;
    q=push(q,tree);
    tnode cur=NULL;
    for (int i=0;i<level;i++)
    {
        while (now>0)
        {
            cur=(getel(q)->data);
            if ((cur->right)!=NULL)
            {
                total++;
                q=push(q,cur->right);
                printf("%d  %d\n",total,cur->right->data);
            }
            if ((cur->left)!=NULL)
            {
                total++;
                q=push(q,cur->left);
                printf("%d  %d\n",total,cur->left->data);
            }
            now--;
            q=pop(q);    
        }
        now=total;
        total=0;
    }
    res=now;
    return res;
}

int main(void)
{
    tnode t=NULL;
    /*int a=5;
    int b=6;
    int c=3;
    int d=2;
    int e=7;
    int f=4;
    int g=8;*/
    t=(tnode)malloc(sizeof(streenode));
    t->data=5;
    t->right=(tnode)malloc(sizeof(streenode));
    t->left=(tnode)malloc(sizeof(streenode));
    t->right->data=6;
    t->left->data=3;
    t->left->right=NULL;
    t->left->left=(tnode)malloc(sizeof(streenode));
    t->left->left->data=7;
    t->left->left->right=NULL;
    t->left->left->left=(tnode)malloc(sizeof(streenode));
    t->left->left->left->data=8;
    t->left->left->left->left=NULL;
    t->left->left->left->right=NULL;
    t->right->left=(tnode)malloc(sizeof(streenode));
    t->right->left->data=4;
    t->right->left->left=NULL;
    t->right->left->right=NULL;
    t->right->right=(tnode)malloc(sizeof(streenode));
    t->right->right->data=2;
    t->right->right->left=NULL;
    t->right->right->right=NULL;
    /*makenode(&t,a);
    makenode(&t,b);
    makenode(&t,c);
    makenode(&t,d);
    makenode(&t,e);
    makenode(&t,f);
    makenode(&t,g);*/
    int tie=count_ties(t,3);
    printf("%d\n", tie);
    //cleartree(t);
    return 0;
}