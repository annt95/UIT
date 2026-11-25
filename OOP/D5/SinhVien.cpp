//
// Created by Uyên on 25/11/26.
//

#include "SinhVien.h"
#include <iostream>

SinhVien::SinhVien(
        string mssv,
        string hoTen,
        unsigned short ngaySinh,
        unsigned short thangSinh,
        unsigned short namSinh,
        unsigned short soTCTL) :
        mssv(mssv), hoTen(hoTen), ngaySinh(ngaySinh), thangSinh(thangSinh),
        namSinh(namSinh), soTCTL(soTCTL)
{
}

string SinhVien::getMssv() {
    return mssv;
}

string SinhVien::getHoTen() {
    return hoTen;
}

unsigned short SinhVien::getNgaySinh() {
    return ngaySinh;
}

unsigned short SinhVien::getThangSinh() {
    return thangSinh;
}

unsigned short SinhVien::getNamSinh() {
    return namSinh;
}

unsigned short SinhVien::getSoTCTL() {
    return soTCTL;
}

void SinhVien::input() {
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> ngaySinh >> thangSinh >> namSinh;
    cout << "Nhap so tin chi tich luy: ";
    cin >> soTCTL;
}

void SinhVien::output() {
    cout << "MSSV: " << mssv
         << " | Ho ten: " << hoTen
         << " | Ngay sinh: " << ngaySinh << "/" << thangSinh << "/" << namSinh
         << " | So TCTL: " << soTCTL << endl;
}


