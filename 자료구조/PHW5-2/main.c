#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100
#define SWAP(i, j, t) t = i; i = j; j = t;

void selection_sort(int[], int);
void quick_sort(int arr[], int left, int right);

struct table {
    int columns[3];
};

int main() {

    struct table t1[15];
    struct table t2[10];

    srand(time(NULL));
    int random;

    for(int i=0; i<15; i++){
        for(int j=0; j<3; j++){
            random = (rand()%98 + 2);
            t1[i].columns[j] = random;
        }
    }

    t1[9].columns[2] = 55;
    t1[13].columns[2] = 55;

    for(int i=0; i<10; i++){
        for(int j=0; j<3; j++){
            random = (rand()%98 + 2);
            t2[i].columns[j] = random;
        }
    }

    t2[4].columns[0] = 55;

    printf("<TABLE 1>\n");
    printf("----------------\n");
    for(int i=0; i<15; i++){
        for(int j=0; j<3; j++){
            printf("|%3d ", t1[i].columns[j]);
        }
        printf("|");
        printf("\n");
        printf("----------------\n");
    }

    printf("\n\n");

    printf("<TABLE 2>\n");
    printf("----------------\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<3; j++){
            printf("|%3d ", t2[i].columns[j]);
        }
        printf("|");
        printf("\n");
        printf("----------------\n");
    }

    printf("\n\n");

//    int selection1[15];
//    for(int i=0; i<15; i++){
//        selection1[i] = t1[i].columns[2];
//    }
//    selection_sort(selection1, 15);
//    for(int i = 0 ; i < 15; i ++) {
//        t1[i].columns[2] = selection1[i];
//    }
//
//    printf("Duplex Selction Sort \n<TABLE 1 on Column3>\n");
//    printf("----------------\n");
//    for(int i=0; i<15; i++){
//        for(int j=0; j<3; j++){
//            printf("|%3d ", t1[i].columns[j]);
//        }
//        printf("|");
//        printf("\n");
//        printf("----------------\n");
//    }
//
//    printf("\n\n");
//
//    int selection2[10];
//    for(int i=0; i<10; i++){
//        selection2[i] = t2[i].columns[0];
//    }
//    selection_sort(selection2, 10);
//    for(int i = 0 ; i < 10; i ++) {
//        t2[i].columns[0] = selection2[i];
//    }
//
//    printf("Duplex Selction Sort \n<TABLE 2 on Column1>\n");
//    printf("----------------\n");
//    for(int i=0; i<10; i++){
//        for(int j=0; j<3; j++){
//            printf("|%3d ", t2[i].columns[j]);
//        }
//        printf("|");
//        printf("\n");
//        printf("----------------\n");
//    }

//    int quick1[15];
//    for(int i=0; i<15; i++){
//        quick1[i] = t1[i].columns[2];
//    }
//    quick_sort(quick1, 0, 15-1);
//    for(int i = 0 ; i < 15; i ++) {
//        t1[i].columns[2] = quick1[i];
//    }
//
//    printf("Quick Sort \n<TABLE 1 on Column3>\n");
//    printf("----------------\n");
//    for(int i=0; i<15; i++){
//        for(int j=0; j<3; j++){
//            printf("|%3d ", t1[i].columns[j]);
//        }
//        printf("|");
//        printf("\n");
//        printf("----------------\n");
//    }
//
//    printf("\n\n");
//

    int quick2[10];
    for(int i=0; i<10; i++){
        quick2[i] = t2[i].columns[0];
    }
    quick_sort(quick2, 0, 10-1);
    for(int i = 0 ; i < 10; i ++) {
        t2[i].columns[0] = quick2[i];
    }

    printf("Quick Sort \n<TABLE 2 on Column1>\n");
    printf("----------------\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<3; j++){
            printf("|%3d ", t2[i].columns[j]);
        }
        printf("|");
        printf("\n");
        printf("----------------\n");
    }
    return 0;
}

void selection_sort(int num[], int n){
    int left = 0;
    int right = n-1;
    int minIdx = -1, maxIdx = -1, min = MAX, max = MIN;
    int tmp;

    while(left < right){
        for(int i = left; i <= right; i++){
            if(max < num[i]){
                maxIdx = i;
                max = num[i];
            }
            if(min > num[i]){
                minIdx = i;
                min = num[i];
            }
        }
        if(maxIdx == left && minIdx == right){
            SWAP(num[right], num[maxIdx], tmp)
        }
        else{
            SWAP(num[right], num[maxIdx], tmp)
            SWAP(num[left], num[minIdx], tmp)
        }
        min = MAX;
        max = MIN;
        left++;
        right--;
    }
}

void Swap(int arr[], int a, int b) // a,b 스왑 함수
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;

    while (low <= high) // 교차되기 전까지 반복한다
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정
        {
            low++; // low를 오른쪽으로 이동
        }
        while (high >= (left+1)  && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행
        {
            Swap(arr, low, high); //low와 high를 스왑
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환
    return high;  // 옮겨진 피벗의 위치정보를 반환

}


void quick_sort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right); // 둘로 나누어서
        quick_sort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        quick_sort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}