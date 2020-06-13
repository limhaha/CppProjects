//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 10
//
//struct queue {
//    int key;
//    struct queue *next
//};
//
//void enqueue(int value);
//int dequeue();
//int queue_empty();
//int queue_full();
//
//struct queue *front = NULL;
//struct queue *rear = NULL;
//
//int count = 0;
//
//int main() {
//    int num, key;
//
//    printf("*Enter Number*\n1.enqueue\n2.dequeue\n3.End program\n?: ");
//    scanf("%d", &num);
//    while (num != 3) {
//        switch (num) {
//            case 1:
//                if (queue_full()) {
//                    printf("Queue is full.\n");
//                    break;
//                } else {
//                    printf("Enqueue value : ");
//                    scanf("%d", &key);
//                    enqueue(key);
//                    break;
//                }
//            case 2:
//                if (queue_empty()) {
//                    printf("Queue is empty.\n");
//                    break;
//                }
//                else {
//                    printf("Dequeue value : %d\n", dequeue());
//                    break;
//                }
//        }
//        printf("? : ");
//        scanf("%d", &num);
//    }
//}
//
//void enqueue(int value) {
//
//    struct queue *newPtr;
//    newPtr = malloc(sizeof(struct queue));
//
//    if (newPtr != NULL) {
//
//        newPtr->key = value;
//        newPtr->next = NULL;
//
//        if(count==0){
//            front = newPtr;
//        }
//        else{
//            rear->next = newPtr;
//        }
//
//        rear = newPtr;
//        count++;
//    }
//}
//
//int dequeue() {
//    int dequeueValue;
//    dequeueValue = front->key;
//    front = front->next;
//    count--;
//    return dequeueValue;
//}
//
//int queue_empty() {
//    if (count==0) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//int queue_full() {
//    if (count >= SIZE) {
//        return 1;
//    } else {
//        return 0;
//    }
//}

#include <stdio.h>

int main(){
    char str[10]={0};
    int a=0, i;
    printf("10개 이하의 영문 소문자를 공백없이 입력>>");
    scanf("%s", str);
    for(i=0;i<10;i++)
        a+=str[i];
    printf("ASCII코드값을 더한 값 : %d\n", a);
    return 0;

}