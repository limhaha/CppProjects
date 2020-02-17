#include <iostream>

using namespace std;

int main(){
    int n;
    string star = "*";
    string blank = "";
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=n; j>i; j--){
            blank = blank + " ";
        }
        cout << blank << star << endl;
        star = star + "*";
        blank = "";
        cin.tie(NULL);
    }
    return 0;
}