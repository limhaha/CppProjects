#include <stdio.h>

#define SIZE 10

int queue1[SIZE], queue2[SIZE];

int front1 = -1, front2 = -1, rear1 = -1, rear2 = -1;

void push(int);
void enqueue1(int), enqueue2(int);
int pop();
int dequeue1(), dequeue2();
int stack_full();
int stack_empty();

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
                }
                else {
                    printf("Push value : ");
                    scanf("%d", &key);
                    push(key);
                    break;
                }

            case 2:
                if (stack_empty()) {
                    printf("Stack is empty.\n");

                    front1 = -1;
                    rear1 = -1;
                    break;
                }
                else {
                    printf("Pop value : %d\n", pop());
                    break;
                }
        }

        front2 = -1;
        rear2 = -1;

        printf("? : ");
        scanf("%d", &num);
    }
}

void push(int value){
    enqueue1(value);
}

void enqueue1(int value){
    if(front1 == -1){
        front1++;
    }

    rear1++;
    queue1[rear1] = value;
}

void enqueue2(int value){
    if(front2 == -1){
        front2++;
    }

    rear2++;
    queue2[rear2] = value;
}

int pop(){
    int dequeueVal = queue1[rear1];

    for(int i=front1; i<rear1; i++){
        enqueue2(queue1[i]);
    }

    for(int i=front1; i<rear1; i++){
        dequeue1();
    }

    rear1 = -1;

    for(int i=front2; i<=rear2; i++){
        enqueue1(queue2[i]);
    }

    for(int i=front2; i<=rear2; i++){
        dequeue2();
    }
    if(front2 == -1){
        rear1 = -1;
    }

    return dequeueVal;
}

int dequeue1(){
    queue1[front1] = NULL;
    rear1--;

    for(int i=0; i< rear1+1; i++){
        queue1[i] = queue1[i+1];
    }
    return 0;
}

int dequeue2(){
    queue2[front2] = NULL;
    rear2--;

    for(int i=0; i< rear2+1; i++){
        queue2[i] = queue2[i+1];
    }
    return 0;
}

int stack_full(){
    if(rear1 == 9){
        return 1;
    }
    else{
        return 0;
    }
}

int stack_empty(){
    if(rear1 == -1){
        return 1;
    }
    else{
        return 0;
    }
}