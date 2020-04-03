#include <stdio.h>
#define SIZE 10

int front = -1;
int rear = -1;
int queue[SIZE];

void enqueue(int value);
int dequeue();
int queue_full();
int queue_empty();

int main() {

    for(int i=0; i<10; i++){
        enqueue(i);
    }

    for(int j=0; j<11; j++){
        dequeue();
    }
}

void enqueue(int value){
    if(queue_full()){
        printf("Queue is full\n");
    }
    else{
        rear = (rear+1) % SIZE;
        queue[rear] = value;
    }
}

int dequeue(){
    if(queue_empty()){
        printf("Queue is empty\n");
    }
    else{
        front = (front+1) % SIZE;
        printf("%d\n", queue[front]);
    }
}

int queue_full(){
    int tmp = (rear+1)%SIZE;
    if(tmp == front){
        return 1;
    }
    else{
        return 0;
    }
}

int queue_empty(){
    if(front == rear){
        return 1;
    }
    else{
        return 0;
    }
}