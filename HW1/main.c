#include <stdio.h>
#include <stdlib.h>

struct stack{
    int key;
    struct stack *next
};

void push(int value);
int pop();
int stack_empty();
int stack_full();

struct stack *top = NULL;

int main(){
    int value;
    printf("");
}

void push(int value){
    struct stack *newPtr;
    newPtr = malloc(sizeof(struct stack));
    if(newPtr != NULL){
        newPtr->key = value;
        newPtr->next = top;
        top = newPtr;
    }
}