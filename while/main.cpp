#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
int is_full();
int is_empty();
void push(int key);
int pop();

int main()
{
    int dec;
    int temp;
    int i;
    int k;

    for (i = 0; i < 5; i++)
    {
        printf("\nType a decimal number: \n");
        scanf("%d", &dec);

        while (dec >= 1)
        {
            if (is_full() != -1)
            {
                temp = dec % 2;
                push(temp);
                dec = dec / 2;
            }
        }

        printf("\nBinary number is : \n");

        while (top != -1)
        {
            if (is_empty() != -1)
            {
                k = pop();
                printf("%d", k);
            }
        }
    }
    return 0;
}

int is_full()
{
    if (top == MAX_SIZE - 1)
        return -1;
    else
        return 0;
}

int is_empty()
{
    if (top == -1)
        return -1;
    else
        return 0;
}

void push(int key)
{
    top++;
    stack[top] = key;
}

int pop()
{
    int delete_key;
    delete_key = stack[top];
    top—;
    return delete_key;
}


//
//  main.c
//  phw2
//
//  Created by 서경호 on 2020/04/15.
//  Copyright © 2020 서경호. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int tree_level;
    int key;
    int childkey;
    struct tree* leftchild;
    struct tree* rightchild;
}Tree;

void Convert_Bin_Tree(Tree** tree, int level, int key2, int childkey2);
void search(Tree* tree, int key2);
void Preorder(Tree* tree);

Tree* parentptr = NULL;
Tree* searchtreeptr = NULL;
Tree* newtreeptr = NULL;

void main()
{
    int option;
    int tree_level, key2, childkey2;

    printf("First binary tree\n");

    do
    {
        printf("(1) : convert a tree , (2) : exit \n");
        printf("Select a menu : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Type the input data for each node of a general tree (level, key, child key)\n");
                scanf("%d %d %d", &tree_level, &key2, &childkey2);
                Convert_Bin_Tree(&newtreeptr, tree_level, key2, childkey2);
                break;
            case 2:
                break;
        }
    } while (option != 2);
    printf("\n");
    Preorder(newtreeptr);

    printf("Second binary treen");

    do
    {
        printf("(1) : convert a tree , (2) : exit \n");
        printf("Select a menu : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Type the input data for each node of a general tree (level, key, child key)\n");
                scanf("%d %d %d", &tree_level, &key2, &childkey2);
                Convert_Bin_Tree(&newtreeptr,tree_level, key2, childkey2);
                break;
            case 2:
                break;
        }
    } while (option != 2);
    printf("\n");
    Preorder(newtreeptr);
}

void Convert_Bin_Tree(Tree** tree, int level, int key2, int childkey2)
{
    Tree* ptr = NULL;
    searchtreeptr = NULL;

    if (tree != NULL)
    {
        search(*tree, key2);
    }

    ptr = (struct tree*)malloc(sizeof(struct tree));
    ptr->tree_level = level;
    ptr->key = key2;
    ptr->childkey = childkey2;
    ptr->leftchild = NULL;
    ptr->rightchild = NULL;
    if (*tree == NULL)
    {
        *tree = ptr;
        parentptr = ptr;
    }
    else
    {
        if (searchtreeptr && searchtreeptr ->tree_level + 1 == ptr->tree_level)
        {
            searchtreeptr->leftchild = ptr;
            parentptr = ptr;
        }
        else
        {
            parentptr->rightchild = ptr;
            parentptr = ptr;
        }
    }
}

void search(Tree* tree, int key2)
{
    if (tree != NULL)
    {
        if (tree->childkey == key2)
        {
            searchtreeptr = tree;
            return;
        }
        search(tree->leftchild, key2);
        search(tree->rightchild, key2);
    }
}


void Preorder(Tree* tree)
{
    if (tree)
    {
        printf("%d\n", tree->key);
        Preorder(tree->leftchild);
        Preorder(tree->rightchild);
    }
}

