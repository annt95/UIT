#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    bool laNguyenTo = (n >= 2);

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            laNguyenTo = false;
            break;
        }
    }

    if (laNguyenTo) {
        cout << n << " la so nguyen to.";
    } else {
        cout << n << " khong la so nguyen to.";
    }

    return 0;
}
