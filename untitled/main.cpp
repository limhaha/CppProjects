#include <iostream>

using namespace std;

int main(){
    using salary = double;
    salary peter = 100.12;
    salary &sangwon = peter;
    cout << "peter's memory address = " << &peter << endl;
    cout << "sangwon's memory address = " << &sangwon << endl;
    return 0;
}

const float PI = 3.1415926;