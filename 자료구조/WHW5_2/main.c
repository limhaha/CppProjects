#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH 9
#define HASH_KEY(key) key%MAX_HASH


int hashTable[MAX_HASH] ;

void AddHashData(int key){
    int index;
    int flag = 0, i;
    int hkey, hash2;

    hkey = key % MAX_HASH;
    hash2 = 1 + key %5;
    for(i=0; i<MAX_HASH; i++){
        index = (hkey + i*hash2) % MAX_HASH;
        if(hashTable[index] == NULL){
            hashTable[index] = key;
            break;
        }
    }
    if(i == MAX_HASH + 1){
        printf("cannot be stored\n");
    }
}

void display(){
    printf("\nelements in the hash table are\n");
    for(int i=0; i<10; i++){
        printf("\nindex %d\n", i);
        printf("%d", hashTable[i]);
    }
}

int main() {
    int keyList[8] = {20, 38, 175, 182, 90, 100, 34, 202};
    for(int i=0; i<8; i++){
        AddHashData(keyList[i]);
    }

    display();
    return 0;
}
