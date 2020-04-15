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
void preorder(Tree* tree);

Tree* parentptr = NULL;
Tree* searchtreeptr = NULL;
Tree* newtreeptr = NULL;

void main()
{
    int option;
    int tree_level, key2, childkey2;

    printf("-----First binary tree-----\n");

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
    preorder(newtreeptr);

    printf("-----Second binary tree-----\n");

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
    preorder(newtreeptr);
}
/* Convert a general tree to binary tree
   input : address of tree, level of tree, key and child key , output: none
*/
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
/* Search node appropriate location in tree
   input: address of tree and key , output: none
*/
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

/* Print binary tree's keys as preorder format
   input: address of tree , output: none
*/
void preorder(Tree* tree)
{
    if (tree)
    {
        printf("%d\n", tree->key);
        preorder(tree->leftchild);
        preorder(tree->rightchild);
    }