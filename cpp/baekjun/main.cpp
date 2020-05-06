#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int c, n;
    int score[1000];

    cin >> c;

    for(int i=0; i<c; i++){
        cin >> n;
        int sum = 0;
        double mean;
        int cnt = 0;
        for(int j=0; j<n; j++){
            cin >> score[j];
            sum += score[j];
        }
        mean = (double)sum / n;

        for(int j=0; j<n; j++){
            if(mean < score[j]) cnt++;
        }

        cout << fixed;
        cout.precision(3);
        cout << (double)cnt/n * 100 << '%' << endl;
    }

    return 0;
}
