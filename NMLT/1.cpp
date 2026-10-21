#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Nhap mot so nguyen: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << n << " la so chan.";
    } else {
        cout << n << " la so le.";
    }

    return 0;
}