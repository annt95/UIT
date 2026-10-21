#include <iostream>
using namespace std;

int main() {
    float diem;
    int xepLoai;

    cout << "Nhap diem trung binh: ";
    cin >> diem;

    if (diem < 0 || diem > 10) {
        cout << "Diem khong hop le.";
        return 0;
    }

    if (diem >= 8) {
        xepLoai = 1;
    } else if (diem >= 6.5) {
        xepLoai = 2;
    } else if (diem >= 5) {
        xepLoai = 3;
    } else if (diem >= 3.5) {
        xepLoai = 4;
    } else {
        xepLoai = 5;
    }

    switch (xepLoai) {
        case 1:
            cout << "Hoc luc Gioi.";
            break;
        case 2:
            cout << "Hoc luc Kha.";
            break;
        case 3:
            cout << "Hoc luc Trung binh.";
            break;
        case 4:
            cout << "Hoc luc Yeu.";
            break;
        case 5:
            cout << "Hoc luc Kem.";
            break;
    }

    return 0;
}