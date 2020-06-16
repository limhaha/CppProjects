#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH 33
#define HASH_KEY(key) key%MAX_HASH

typedef struct Node{
    char id[10];
    struct Node* hashNext;
}Node;

void AddHashData(int key, Node* node);
void InsertHashData(char id[]);
void PrintAllHashData();
void DelHashData(char id[]);
int SearchHashData(char id[]);

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

int insert_key;
void InsertHashData(char id[]){
    printf("INSERT %s\n", id);
    if(SearchHashData(id)){
        printf("Exist!\n");
        return;
    }

    Node* Insertnode = (Node*)malloc(sizeof(Insertnode));
    strcpy(Insertnode->id, id);

    insert_key = 0;
    printf("%s\n", Insertnode->id);

    for(int j=0; j<strlen(Insertnode->id); j++){
        insert_key += Insertnode->id[j];
    }


    int hash_key = HASH_KEY(insert_key);

    if(hashTable[hash_key] == NULL){
        hashTable[hash_key] = Insertnode;
    }
    else{
        Insertnode->hashNext = hashTable[hash_key];
        hashTable[hash_key]= Insertnode;
    }
    printf("Inserted!\n");
}


void PrintAllHashData(){
    printf("<Print HASH DATA>");
    for(int i=0; i<MAX_HASH; i++){
        printf("\nidx %d : ", i);
        if(hashTable[i] != NULL){
            Node* node = hashTable[i];
            while (node->hashNext){
                printf("%s ", node->id);
                node = node->hashNext;
            }
            printf("%s", node->id);
        }
        else{
            printf("NULL");
        }
    }
    printf("\n\n");
}

int sum_del;
void DelHashData(char id[]){
    sum_del = 0;
    printf("DELETE %s\n", id);

    for(int j=0; j<strlen(id); j++){
        sum_del += id[j];
    }

    int hash_key = HASH_KEY(sum_del);

    if(hashTable[hash_key] == NULL){
        return;
    }

    Node* delNode = NULL;
    
    if (strcmp(hashTable[hash_key]->id, id) == 0){
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashNext;
        printf("Deleted!\n");
    }
    else{
        Node* node = hashTable[hash_key];
        Node* next = node->hashNext;
        while (next){
            if(strcmp(next->id, id) == 0){
                node->hashNext = next->hashNext;
                delNode = next;
                printf("Deleted!\n");
                break;
            }
            node = next;
            next = node->hashNext;
            printf("Not Found!\n");
        }
    }
    free(delNode);
}

int sum_srch;
int SearchHashData(char id[]){
    sum_srch = 0;
//    printf("SEARCH %s\n", id);

    for(int j=0; j<strlen(id); j++){
        sum_srch += id[j];
    }


    int hash_key = HASH_KEY(sum_srch);

    if(hashTable[hash_key] == NULL){
//        printf("Not Found!\n");
        return 0;
    }

    if (strcmp(hashTable[hash_key]->id, id) == 0){
//        printf("Found!\n");
        return 1;
    }
    else{
        Node* node = hashTable[hash_key];
        while (node->hashNext){
            if(strcmp(node->hashNext->id, id) == 0){
//                printf("Found!\n");
                return 1;
                break;
            }
            node = node->hashNext;
//            printf("Not Found!\n");
            return 0;
        }
    }

}


int main(){
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
            fscanf(fp, "%s", buff);
//            fgets(buff, sizeof(buff), fp);
            Node* node = (Node*)malloc(sizeof(Node));

            strcpy(node->id, buff);
            node->hashNext = NULL;
            int sum = 0;
            
            for(int j=0; j<10; j++){
                sum += node->id[j];
            }


            AddHashData(sum, node);

            i++;
        }
    }


    int opt;
    char str[10];
    printf("1.INSERT  2.DELETE  3.SEARCH  4.PRINT \n");

    while(opt != 5) {
        printf("Enter Option : ");
        scanf("%d", &opt);
        switch (opt) {
            case 1 :
                printf("Type String for INSERT : ");
                scanf("%s", str);
                printf("\n");
                InsertHashData(str);
                break;

            case 2 :
                printf("Type String for DELETE : ");
                scanf("%s", str);
                printf("\n");
                DelHashData(str);
                break;

            case 3 :
                printf("Type String for SEARCH : ");
                scanf("%s", str);
                printf("\n");
                printf("SEARCH %s\n", str);
                if (SearchHashData(str)) {
                    printf("FOUND!\n");
                } else {
                    printf("Not Found!\n");
                }
                break;

            case 4 :
                PrintAllHashData();
                break;
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
    
}