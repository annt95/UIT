//
// Created by Uyên on 25/11/26.
//
#include <iostream>
#include <string>
using namespace std;

class SinhVien {
    string mssv;
    string hoTen;
    unsigned short ngay;
    unsigned short thang;
    unsigned short nam;
    unsigned short soTCTL;
public:
    SinhVien();
    SinhVien(
        string mssv,
        string hoTen,
        unsigned short ngay,
        unsigned short thang,
        unsigned short nam,
        unsigned short soTCTL);
    void input();
    void output();
    unsigned short getSoTCTL();
};

SinhVien::SinhVien() : mssv(""), hoTen(""), ngay(1), thang(1), nam(2000), soTCTL(0) {}

SinhVien::SinhVien(string mssv, string hoTen,
                   unsigned short ngay, unsigned short thang, unsigned short nam,
                   unsigned short soTCTL) {
    this->mssv = mssv;
    this->hoTen = hoTen;
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
    this->soTCTL = soTCTL;
}

void SinhVien::input() {
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> ngay >> thang >> nam;
    cout << "Nhap so tin chi tich luy: ";
    cin >> soTCTL;
}

void SinhVien::output() {
    cout << "MSSV: " << mssv
         << " | Ho ten: " << hoTen
         << " | Ngay sinh: " << ngay << "/" << thang << "/" << nam
         << " | So TCTL: " << soTCTL << endl;
}

unsigned short SinhVien::getSoTCTL() {
    return soTCTL;
}

int main() {
    // Minh họa tạo lập khi biết thông tin đầy đủ
    SinhVien demo("23520001", "Nguyen Van A", 15, 8, 2005, 60);
    cout << "Sinh vien mau:\n";
    demo.output();

    // Nhập 2 sinh viên
    SinhVien sv1, sv2;
    cout << "\n--- Nhap sinh vien 1 ---\n";
    sv1.input();
    cout << "--- Nhap sinh vien 2 ---\n";
    sv2.input();

    cout << "\n--- Thong tin ---\n";
    sv1.output();
    sv2.output();

    // So sánh số tín chỉ tích lũy
    if (sv1.getSoTCTL() > sv2.getSoTCTL()) {
        cout << "\nSinh vien co nhieu tin chi hon:\n";
        sv1.output();
    } else if (sv1.getSoTCTL() < sv2.getSoTCTL()) {
        cout << "\nSinh vien co nhieu tin chi hon:\n";
        sv2.output();
    } else {
        cout << "\nHai sinh vien co so tin chi bang nhau.\n";
    }

    return 0;
}
