#include <stdio.h>
#define SIZE 5

void insert(int value);
int delete();
int front = 0, rear = 0;

int queue[SIZE];

int main() {
    int num, key;

    printf("*Enter Number*\n1.enqueue\n2.dequeue\n3.End program\n?: ");
    scanf("%d", &num);
    while (num != 3) {
        switch (num) {
            case 1:
                if((front == 1 && rear == SIZE) || (front == rear + 1)){
                    printf("OVERFLOW.\n");
                    break;
                }
                 else {
                    printf("Enqueue value : ");
                    scanf("%d", &key);
                    insert(key);
                    break;
                }

            case 2:
                if(front == 0){
                    printf("Queue is empty.\n");
                    break;
                }
                else {
                    printf("Dequeue value : %d\n", delete());
                    break;
                }
        }
        printf("? : ");
        scanf("%d", &num);
    }

    return 0;
}

void insert(int value){
    if (front == 0 && rear == 0){
        front = 1;
        rear = 1;
        queue[rear-1] = value;
    }

    if(rear == SIZE){
        rear = 1;
        queue[rear-1] = value;
    }

    else{
        rear ++;
        queue[rear-1] = value;
    }
}

int delete(){
    int temp;

    if(front == SIZE){
        front = 1;
        return queue[SIZE-1];
    }

    if(front == rear){
        temp = front;
        front = 0;
        rear = 0;
        return queue[temp-1];
    }
    else{
        front++;
        return queue[front-1];
    }
}