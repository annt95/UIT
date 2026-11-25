#include <iostream>

#include "SinhVien.h"


int main() {
    SinhVien sv1("sv001", "Sinh vien 001", 15, 8, 2005, 60);
    SinhVien sv2("sv002", "Sinh vien 002", 20, 10, 2005, 75);

    sv1.output();
    sv2.output();

    if (sv1.getSoTCTL() > sv2.getSoTCTL()) {
        cout << "Sinh vien co nhieu tin chi hon: " << sv1.getHoTen() << endl;
    } else if (sv1.getSoTCTL() < sv2.getSoTCTL()) {
        cout << "Sinh vien co nhieu tin chi hon: " << sv2.getHoTen() << endl;
    } else {
        cout << "Hai sinh vien co so tin chi bang nhau." << endl;
    }

    return 0;
}

