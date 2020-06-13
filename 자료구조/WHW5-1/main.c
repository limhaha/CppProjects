#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH 33
#define HASH_KEY(key) key%MAX_HASH

typedef struct Node{
    char id[10];
    struct Node* hashNext;
}Node;

Node* hashTable[MAX_HASH];

void AddHashData(int key, Node* node){
    int hash_key = HASH_KEY(key);

    if(hashTable[hash_key] == NULL){
        hashTable[hash_key] = node;
    }
    else{
        node->hashNext = hashTable[hash_key];
        hashTable[hash_key]= node;
    }
}

void PrintAllHashData(){
    printf("Print HASH DATA\n");
    for(int i=0; i<MAX_HASH; i++){
        printf("<idx: %d>\n", i);
        if(hashTable[i] != NULL){
            Node* node = hashTable[i];
            while (node->hashNext){
                printf("%s", node->id);
                node = node->hashNext;
            }
            printf("%s", node->id);
        }
        else{
            printf("NULL\n");
        }
    }
    printf("\n\n");
}


void DelHashData(char id[]){
    int sum = 0;

    for(int j=0; j<10; j++){
        sum += id[j];
    }
    
    int hash_key = HASH_KEY(sum);
    printf("%d", hash_key);
    if(hashTable[hash_key] == NULL){
        return;
    }

    Node* delNode = NULL;
    
    if (strcmp(hashTable[hash_key]->id, id) == 0){
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashNext;
    }
    else{
        Node* node = hashTable[hash_key];
        Node* next = node->hashNext;
        while (next){
            if(strcmp(next->id, id) == 0){
                node->hashNext = next->hashNext;
                delNode = next;
                break;
            }
            node = next;
            next = node->hashNext;
        }
    }
    free(delNode);
}


Node* FindHashData(char *id){
    int sum = 0;

    for(int j=0; j<10; j++){
        sum += id[j];
    }
    printf("%d", sum);
    
    int hash_key = HASH_KEY(sum);
    if(hashTable[hash_key] == NULL){
        return NULL;
    }

    if(hashTable[hash_key]->id == id){
        return hashTable[hash_key];
    }
    else{
        Node* node = hashTable[hash_key];
        while (node-> hashNext){
            if(node->hashNext->id == id){
                return node->hashNext;
            }
            node = node->hashNext;
        }
    }
    return 0;
}


int main(){
    char saveidx[10][101] = {0, };
    FILE *fp;
    char buff[100];
    
    fp = fopen("/Users/halim/CLionProjects/자료구조/WHW5-1/keyinput.txt", "r");
    if(fp == NULL){
        printf("File cannot be opened\n");
    }
    if(fp != NULL){
        int i = 0;
        while (!feof(fp)){
            if(i == 20) break;
            fgets(buff, 100, fp);
            Node* node = (Node*)malloc(sizeof(Node));
            strcpy(node->id, buff);
            
            node->hashNext = NULL;
            int sum = 0;
            
            for(int j=0; j<10; j++){
                sum += node->id[j];
            }
            AddHashData(sum-23, node);
            saveidx[10][i] = node->id;
            printf("%d 아스키 코드값을 더한값 : %d\n", i+1, sum-23);
            i++;
        }
    }
    
//    int keyList[8] = {20, 38, 175, 182, 90, 100, 34, 202};
//    for(int i=0; i<8; i++){
//        Node* node = (Node*) malloc(sizeof(Node));
//        node->id = keyList[i];
//        node->hashNext = NULL;
//        AddHashData(node->id, node);
//        saveidx[i] = node->id;
//    }
    PrintAllHashData();
    
    printf("alalalal");
    DelHashData("Purple");
//    
//    PrintAllHashData();
    return 0;
    
}