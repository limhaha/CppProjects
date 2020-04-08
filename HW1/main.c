#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct stack {
    int key;
    struct stack *next
};

void push(int value);

int pop();

int stack_empty();

int stack_full();

struct stack *top = NULL;
int count = 0;

int main() {
    int num, key;

    printf("*Enter Number*\n1.push\n2.pop\n3.End program\n?: ");
    scanf("%d", &num);
    while (num != 3) {
        switch (num) {
            case 1:
                if (stack_full()) {
                    printf("Stack is full.\n");
                    break;
                } else {
                    printf("Push value : ");
                    scanf("%d", &key);
                    push(key);
                    break;
                }
            case 2:
                if (stack_empty()) {
                    printf("Stack is empty.\n");
                    break;
                }
                else {
                    printf("Pop value : %d\n", pop());
                    break;
                }
        }
                printf("? : ");
                scanf("%d", &num);
    }
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

//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//
//typedef struct node
//{
//    int key;
//    struct node *next;
//} Node;
//
//typedef struct stack
//{
//    Node *top;
//} Stack;
//
//void push(Stack *stack, int key);
//int pop(Stack *stack);
//int stack_full();
//int stack_empty(Stack *stack);
//
//int count = 0;
//
//int main()
//{
//    int key;
//    int num;
//    Stack *stack = NULL;
//
//    printf("*Enter Number*\n1.push\n2.pop\n4.End program\n?: ");
//    scanf("%d", &num);
//    while (num != 4)
//    {
//        switch (num)
//        {
//            case 1:
//                printf("insert DATA : ");
//                scanf("%d", &key);
//                push(&stack, key);
//                break;
//            case 2:
//                pop(&stack);
//                break;
//        }
//        printf("? : ");
//        scanf("%d", &num);
//
//    }
//}
//
//void push(Stack *stack, int key) {
//    if (stack_full()) {
//        printf("Stack is full\n");
//    } else {
//        Node *start = (Node *) malloc(sizeof(Node));
//        if (start == NULL) {
//            printf("Memory not allocated");
//        }
//        start->key = key;
//        start->next = stack->top;
//        stack->top = start;
//        count++;
//    }
//}
//
//int pop(Stack *stack)
//{
//    Node *temp;
//    if (stack_empty(stack))
//    {
//        printf("stack is empty\n");
//        return 0;
//    }
//    temp = stack->top;
//    stack->top = stack->top->next;
//    free(temp);
//    printf("POP!\n");
//    count --;
//    return 1;
//}
//
//int stack_empty(Stack *stack)
//{
//    if (stack->top == NULL)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//
//int stack_full(){
//    if(count >= SIZE){
//        return 1;
//    }
//    else
//        return 0;
//}
//
