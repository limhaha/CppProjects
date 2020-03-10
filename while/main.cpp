#include <iostream>

using namespace std;

int main() {
    int a;
    int count = 0;
    int n = 0;
    cin >> a;
    n = a;
    if (a < 10) {
        n = n * 10;
    }
    a = n;
    while (1) {
        n = ((n % 10) * 10) + (n / 10 + n % 10)%10;
        count++;
        if (n == a) {
            break;

        }
    }
    cout << count << endl;
    return 0;
}
//
//using namespace std;
//
//const int MAX = 1000000;
//
//int main() {
//    int n;
//    cin >> n;
//    int input = 0;
//    int min = MAX;
//    int max = -MAX;
//
//    for (int i = 0; i < n; i++) {
//    }
//}