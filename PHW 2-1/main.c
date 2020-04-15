#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct stack {
    int key;
    struct stack *next
};

void push(int value);

int pop();

int stack_empty();

int stack_full();

void convert(int num);

struct stack *top = NULL;

int count = 0;

int main() {

    int num;
    printf("Enter decimal number : ");
    scanf("%d",&num);
    printf("Binary equivalent : ");
    convert(num);

    return 0;
}

void push(int value) {
    struct stack *newPtr;
    newPtr = malloc(sizeof(struct stack));
    if (newPtr != NULL) {
        newPtr->key = value;
        newPtr->next = top;
        top = newPtr;
        count++;
    }
}

int pop() {
    int popValue;
    popValue = top->key;
    top = top->next;
    count--;
    return popValue;
}

int stack_empty() {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int stack_full() {
    if (count >= SIZE) {
        return 1;
    } else {
        return 0;
    }
}


void convert(int num){
    int rem;

    while(num!=0)
    {
        rem = num%2;
        push(rem);
        num /= 2;
    }
    while(top!= NULL) {
        printf("%d ", pop());
    }
    printf("\n");
}