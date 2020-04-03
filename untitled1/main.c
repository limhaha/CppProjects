#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value);
int pop();
int stack_full();
int stack_empty();

int main(){
    for(int i=0; i<11; i++){
        push(i);
    }
    for(int j=0; j<11; j++){
        pop();
    }
    return 0;
}

void push(int value){
    if(stack_full() == 1){
        printf("stack is full\n");
    }
    else {
        stack[++top] = value;
    }
}

int pop(){
    if(stack_empty() == 1){
        printf("Stack is empty\n");
    }
    else{
        printf ("%d\n",stack[top--]);
    }
}

int stack_full(){
    if(top >= SIZE-1){
        return 1;
    }
    else {
        return 0;
    }
}

int stack_empty(){
    if (top < 0) {
        return 1;
    }

    else{
            return 0;
    }
}