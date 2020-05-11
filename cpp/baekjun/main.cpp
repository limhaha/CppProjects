#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


#define MAX 10001

using namespace std;
int d(int);

int main(){
    vector<bool> selfAry;
    selfAry.assign(MAX, true);
    int notSelfNum;

    for(int i=0; i<MAX; i++){
        notSelfNum = d(i);
        if(notSelfNum>MAX)
            continue;
        selfAry[notSelfNum] = false;
    }
    for(int i=0; i<MAX; i++){
        if(selfAry[i]){
            cout << i <<endl;
        }
    }

    return 0;
}



int d(int n) {
    int num = n;
    do {
        num += n % 10;
    } while ((n /= 10) != 0);

    return num;
}