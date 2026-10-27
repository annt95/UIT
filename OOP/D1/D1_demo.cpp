
#include <iostream>
using namespace std;

struct ST {
    int n;
    float f1;
    char c1;
    float f2;
    char c2;
    char c3;
};

int main() {
    ST x;
    x.n = 10;
    x.f1 = 3.5f;
    x.c1 = 'A';
    x.f2 = 2.75f;
    x.c2 = 'B';
    x.c3 = 'C';
    cout << "Size of struct ST: " << sizeof(ST) << " bytes" << endl;
    cout << x.n << endl;
    cout << x.f1 << endl;
    cout << x.c1 << endl;
    cout << x.f2 << endl;
    cout << x.c2 << endl;
    cout << x.c3 << endl;

    return 0;
}