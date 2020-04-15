#include"stdio.h"
#include"conio.h"
#include"alloc.h"
#include"stdlib.h"
#define n 15
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};
typedef struct node node;
struct stack
{
    int top;
    int number[n];
    struct node *location[n];
};
typedef struct stack stack;
void convert(node **);
void display(node *);
void main()
{
    node *root=NULL;
    clrscr();
    convert(&root);
    printf("\ndata in binary tree :\n");
    display(root);
    getch();
}
void convert(node **root)
{
    char c;
    int pl,level,x;
    stack s;
    node *p=NULL,*ploc=NULL;
    node *newnode=(node *)malloc(sizeof(node));
    s.top=-1;

    if(newnode==NULL)
    {
        printf("memory overflow");
        return;
    }
    if(*root==NULL)
    {
        *root=newnode;
        (*root)->lptr=(*root)->rptr=NULL;
        printf("enter level and data>");
        scanf("%d%d",&level,&x);
        (*root)->data=x;
        s.location[0]=*root;
        s.number[0]=level;
        s.top=0;
    }
    l:printf("to enter a data(y/n)?");
    c=getch();
    if(c=='y')
    {
        printf("\nenter level and data>");
        scanf("%d%d",&level,&x);
        p=(node *)malloc(sizeof(node));
        p->lptr=p->rptr=NULL;
        p->data=x;
        pl=s.number[s.top];
        ploc=s.location[s.top];
        if(level>pl)
            ploc->lptr=p;
        else
        {
            while(pl>level)
            {
                s.top=s.top+1;
                pl=s.number[s.top];
                ploc=s.location[s.top];
            }
            ploc->rptr=p;
            s.top=s.top-1;
        }
        s.top=s.top-1;
        s.number[s.top]=level;
        s.location[s.top]=p;
        goto l;
    }}
void display(node *p)
{
    if(p!=NULL)
    {
        printf(" %d ",p->data);
        display(p->lptr);
        display(p->rptr);
    }
}