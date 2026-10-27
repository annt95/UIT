#include <iostream>
using namespace std;

int main() {
    int n;

    do {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if (n <= 0) {
            cout << "n phai la so nguyen duong. Vui long nhap lai." << endl;
        }
    } while (n <= 0);

    cout << "Cac uoc so cua " << n << " la: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }

    return 0;
}
