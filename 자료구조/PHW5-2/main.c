#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100
#define SWAP(i, j, t) t = i; i = j; j = t;

void selection_sort(int arr[], int n);
void quick_sort(int arr[], int left, int right);
void join(int t1c[], int t2c[], int val);

struct table {
    int columns[3];
};

struct mergetable{
    int coulmns[5];
};

struct table t1[15];
struct table t2[10];

int main() {



    srand(time(NULL));
    int random;

    for(int i=0; i<15; i++){
        for(int j=0; j<3; j++){
            random = (rand()%98 + 2);
            t1[i].columns[j] = random;
        }
    }


    for(int i=0; i<10; i++){
        for(int j=0; j<3; j++){
            random = (rand()%98 + 2);
            t2[i].columns[j] = random;
        }
    }


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

    t1[9].columns[2] = 55;
    t1[13].columns[2] = 55;
    t2[4].columns[0] = 55;


    //Print After Update
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


    int selection1[15];
    for(int i=0; i<15; i++){
        selection1[i] = t1[i].columns[2];
    }
    selection_sort(selection1, 15);
    for(int i = 0 ; i < 15; i ++) {
        t1[i].columns[2] = selection1[i];
    }

    printf("Duplex Selction Sort \n<TABLE 1 on Column3>\n");
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

    int selection2[10];
    for(int i=0; i<10; i++){
        selection2[i] = t2[i].columns[0];
    }
    selection_sort(selection2, 10);
    for(int i = 0 ; i < 10; i ++) {
        t2[i].columns[0] = selection2[i];
    }

    printf("Duplex Selction Sort \n<TABLE 2 on Column1>\n");
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

    int quick1[15];
    for(int i=0; i<15; i++){
        quick1[i] = t1[i].columns[2];
    }
    quick_sort(quick1, 0, 15-1);

    for(int i = 0 ; i < 15; i ++) {
        t1[i].columns[2] = quick1[i];
    }

    printf("Quick Sort \n<TABLE 1 on Column3>\n");
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

    printf("\n\n");

    join(quick1, quick2, 55 );

    return 0;
}

void selection_sort(int arr[], int n){

    int tmp;
    for (int i=0, j=n-1; i<j; i++, j--) {
        int min = arr[i], max = arr[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (arr[k] > max) {
                max = arr[k];
                max_i = k;
            } else if (arr[k] < min) {
                min = arr[k];
                min_i = k;
            }
        }

        SWAP(arr[i], arr[min_i], tmp)

        if (arr[min_i] == max) {
            SWAP(arr[j], arr[min_i], tmp)
        }
        else {
            SWAP(arr[j], arr[max_i], tmp)
        }
    }
}

void Swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high){
        while (low <= right && pivot >= arr[low]){
            low++;
        }
        while (high >= (left+1)  && pivot <= arr[high]){
            high--;
        }
        if (low <= high){
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high);
    return high;
}


void quick_sort(int arr[], int left, int right){
    if (left <= right){
        int pivot = Partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

void join(int t1c[], int t2c[], int val){
    struct mergetable mt[2];
    int n=0;
    int i, j, k;

    for(i=0; i<15; i++){
        if(t1c[i] == val) {
//            printf("%d\n", i);
            for (j=0; j<10; j++) {
                if(t2c[j] == val){
//                    printf("%d\n", j);
                    for(k=0; k<3; k++){
                        mt[n].coulmns[k] = t1[i].columns[k];
                    }
                    for(k=3; k<5; k++){
                        mt[n].coulmns[k] = t2[j].columns[k-2];
                    }
                    n = n+ 1;
                }
            }
        }
    }


    printf("Merge Join of the two tables\n");
    printf("--------------------------\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            printf("|%3d ", mt[i].coulmns[j]);
        }
        printf("|");
        printf("\n");
        printf("--------------------------\n");
    }
}