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

    int demChuSo = 0;
    int temp = n;
    while (temp != 0) {
        temp /= 10;
        demChuSo++;
    }

    cout << "So " << n << " co " << demChuSo << " chu so.";

    return 0;
}
