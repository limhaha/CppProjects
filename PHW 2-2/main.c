#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int tree_level;
    int key;
    int childkey;
    struct tree *lptr;
    struct tree *rptr;
} Tree;

void convert(Tree **tree, int level, int data, int c_data);

void search(Tree *tree, int data);

void preorder(Tree *tree);

Tree *pptr = NULL;
Tree *sptr = NULL;
Tree *newptr = NULL;

int main() {
    int n;
    int tree_level, data, c_data;
    printf("\n1.add node  2.end  ");
    do {
        printf("?:");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Type data general tree (level, key, child_key) : ");
                scanf("%d %d %d", &tree_level, &data, &c_data);
                convert(&newptr, tree_level, data, c_data);
                break;
            case 2:
                break;
        }
    } while (n != 2);
    printf("\n");
    preorder(newptr);

}


void convert(Tree **tree, int level, int data, int c_data) {
    Tree *ptr = NULL;
    sptr = NULL;

    if (tree != NULL) {
        search(*tree, data);
    }

    ptr = (struct tree *) malloc(sizeof(struct tree));
    ptr->tree_level = level;
    ptr->key = data;
    ptr->childkey = c_data;
    ptr->lptr = NULL;
    ptr->rptr = NULL;

    if (*tree == NULL) {
        *tree = ptr;
        pptr = ptr;
    } else {
        if (sptr && (sptr->tree_level + 1 == ptr->tree_level)) {
            sptr->lptr = ptr;
            pptr = ptr;
        } else {
            pptr->rptr = ptr;
            pptr = ptr;
        }
    }
}

void search(Tree *tree, int data) {

    if (tree != NULL) {

        if (tree->childkey == data) {
            sptr = tree;
            return;
        }

        search(tree->lptr, data);
        search(tree->rptr, data);
    }
}

void preorder(Tree *tree) {

    if (tree) {
        printf("%d\n", tree->key);
        preorder(tree->lptr);
        preorder(tree->rptr);
    }
}