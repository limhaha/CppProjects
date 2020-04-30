#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define RMAX 100

typedef struct node
{
    int data;
    struct node *left,*right;
    int ht;
}node;

node *insert(node *,int);

void inorder_1(node *);
void inorder_2(node *);
void inorder_3(node *);
void inorder_4(node *);
void inorder_5(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

int max = 0;

int main()
{
    node *root=NULL;
    int x,n,i,op;
    int arr[200];
    srand((time(NULL)));

    //Random array
    for (int i=2; i<200; i++) {
        int random_no = 1 + (int) rand() % RMAX;
        arr[i] = random_no;
    }
    arr[0] = 15;
    arr[1] = 50;


    //Insert 100 unique key
    root=NULL;
    for(i=0;i<100;i++)
    {
        root=insert(root,arr[i]);
    }

    printf("\n<Search the tree keys 15, 20, 50, 70, 90>\n");
    inorder_1(root);
    printf("\n");

    inorder_2(root);
    printf("<Higest Key : %d>",max);
    printf("\n");

    printf("\n<Keys < 15>\n");
    inorder_3(root);
    printf("\n");

    printf("\n<Keys > 50>\n");
    inorder_4(root);
    printf("\n");

    printf("\n<Keys between 15 and 50>\n");
    inorder_5(root);
    printf("\n");

    return 0;
}

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
    if(x > T->data)		// insert in right subtree
    {
        T->right=insert(T->right,x);
        if(BF(T)==-2)
            if(x>T->right->data)
                T=RR(T);
            else
                T=RL(T);
    }
    else
    if(x<T->data)
    {
        T->left=insert(T->left,x);
        if(BF(T)==2)
            if(x < T->left->data)
                T=LL(T);
            else
                T=LR(T);
    }

    T->ht=height(T);

    return(T);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    if(lh>rh)
        return(lh);

    return(rh);
}

node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}

node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}

node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}

node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);

    return(T);
}

node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}

int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    return(lh-rh);
}


void inorder_1(node *T)
{
    if(T!=NULL)
    {
        inorder_1(T->left);
        if(T->data == 15) {
            printf("15 Found\n");
        }

        if(T->data == 20) {
            printf("20 found\n");
        }

        if(T->data == 50) {
            printf("50 found\n");
        }

        if(T->data == 70) {
            printf("70 found\n");
        }

        if(T->data == 90) {
            printf("90 found\n");
        }

        inorder_1(T->right);
    }
}

void inorder_2(node *T)
{
    if(T!=NULL)
    {
        inorder_2(T->left);
        max = T->data;
        if(max < T->data){
            max = T->data;
        }
        inorder_2(T->right);
    }
}

void inorder_3(node *T)
{
    if(T!=NULL)
    {
        inorder_3(T->left);
        if(T->data < 15) {
            printf("%d ", T->data);
        }
        inorder_3(T->right);
    }
}

void inorder_4(node *T)
{
    if(T!=NULL)
    {
        inorder_4(T->left);
        if(T->data > 50) {
            printf("%d ", T->data);
        }
        inorder_4(T->right);
    }
}

void inorder_5(node *T)
{
    if(T!=NULL)
    {
        inorder_5(T->left);
        if((T->data > 15) && T->data < 50) {
            printf("%d ", T->data);
        }
        inorder_5(T->right);
    }
}
