//
// Created by Uyên on 25/11/26.
//

#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>
using namespace std;

class SinhVien {
    string mssv;
    string hoTen;
    unsigned short ngaySinh;
    unsigned short thangSinh;
    unsigned short namSinh;
    unsigned short soTCTL;
public:
    SinhVien(
        string mssv,
        string hoTen,
        unsigned short ngaySinh,
        unsigned short thangSinh,
        unsigned short namSinh,
        unsigned short soTCTL = 0);
    string getMssv();
    string getHoTen();
    unsigned short getNgaySinh();
    unsigned short getThangSinh();
    unsigned short getNamSinh();
    unsigned short getSoTCTL();
    void input();
    void output();
};

#endif // SINHVIEN_H

