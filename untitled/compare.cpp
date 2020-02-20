#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    int mid;
    cin >> a >> b >> c;

    if (a < 0 || b < 0 || c < 0 || a > 100 || b > 100 || c > 100)
        return 0;

    if (a >= b)
    {
        mid = (b >= c) ? b : (a >= c) ? c : a;
    }
    else // b>a
    {
        mid = (a >= c) ? a : (b >= c) ? c : b;
    }

    cout << mid << endl;

    return 0;
}