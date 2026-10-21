#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double delta, x1, x2;

    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem.";
            } else {
                cout << "Phuong trinh vo nghiem.";
            }
        } else {
            x1 = -c / b;
            cout << "Phuong trinh co mot nghiem: x = " << x1;
        }
    } else {
        delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem.";
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x1;
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "Phuong trinh co hai nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        }
    }

    return 0;
}