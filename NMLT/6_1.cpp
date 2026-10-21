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

    long long S = 0;
    for (int i = 1; i <= n; i++) {
        S += i;
    }

    cout << "S = 1 + 2 + ... + " << n << " = " << S;

    return 0;
}
