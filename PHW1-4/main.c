#include <stdio.h>
#define SIZE 10

int stack1[SIZE], stack2[SIZE];

int top1 = -1, top2 = -1;

void enqueue(int);
void push1(int), push2(int);

int dequeue();
int pop1(), pop2();

int queue_full();
int queue_empty();

int main(){
    int num, key;

    printf("*Enter Number*\n1.enqueue\n2.dequeue\n3.End program\n?: ");
    scanf("%d", &num);
    while (num != 3) {
        switch (num) {
            case 1:
                if (queue_full()) {
                    printf("Queue is full.\n");
                    break;
                } else {
                    printf("Enqueue value : ");
                    scanf("%d", &key);
                    enqueue(key);
                    break;
                }
            case 2:
                if (queue_empty()) {
                    printf("Queue is empty.\n");
                    break;
                }
                else {
                    printf("Dequeue value : %d\n", dequeue());
                    break;
                }
        }
        printf("? : ");
        scanf("%d", &num);
    }
}

void enqueue(int value){
    push1(value);
}

void push1(int value){
    stack1[++top1] = value;
}

void push2(int value){
    stack2[++top2] = value;
}

int dequeue(){
    int popVal = stack1[0];

    if(top1 == 0){
        pop1();
    }

    else{
        for(int i=top1; i>0; i--){
            push2(stack1[i]);
        }

        for(int i=top1; i>=0; i--){
            pop1();
        }

        for(int i=top2; i>=0; i--){
            push1(stack2[i]);
        }

        for(int i=top1; i>=0; i--){
            pop2();
        }

        top2 = -1;
    }

    return popVal;
}

int pop1(){
    stack1[top1] = NULL;
    top1--;
    return 0;
}

int pop2(){
    stack2[top2] = NULL;
    top2--;
    return 0;
}

int queue_full(){
    if(top1 == 9){
        return 1;
    }
    else{
        return 0;
    }
}

int queue_empty(){
    if(top1 == -1){
        return 1;
    }
    else{
        return 0;
    }
}



