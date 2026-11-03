#ifndef D2_DEMO_H
#define D2_DEMO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class ThiSinh {
protected:
    string maTS;
    string hoTen;
    map<string, float> diemMon;

public:
    ThiSinh() : maTS(""), hoTen("") {}
    ThiSinh(string maTS, string hoTen) : maTS(maTS), hoTen(hoTen) {}

    void setMaTS(string ma) { maTS = ma; }
    string getMaTS() const { return maTS; }

    void setHoTen(string ten) { hoTen = ten; }
    string getHoTen() const { return hoTen; }

    void setDiemMon(string mon, float diem) {
        if (diem >= 0 && diem <= 10) diemMon[mon] = diem;
    }

    float getDiemMon(string mon) const {
        auto it = diemMon.find(mon);
        if (it != diemMon.end()) return it->second;
        return -1;
    }

    map<string, float> getAllDiem() const {
        return diemMon;
    }

    void nhap() {
        cout << "Nhap ma thi sinh: ";
        cin >> maTS;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        int n;
        cout << "Nhap so mon: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string mon;
            float diem;
            cout << "Nhap ten mon: ";
            cin >> mon;
            cout << "Nhap diem: ";
            cin >> diem;
            setDiemMon(mon, diem);
        }
    }

    void xuat() const {
        cout << "Ma TS: " << maTS << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem mon: " << endl;
        for (const auto &it : diemMon) {
            cout << "   " << it.first << ": " << it.second << endl;
        }
    }
};

class HocSinh : public ThiSinh {
public:
    HocSinh() : ThiSinh() {}
    HocSinh(string maTS, string hoTen) : ThiSinh(maTS, hoTen) {}
};

class KhoiNganh {
protected:
    vector<HocSinh> dsThiSinh;

public:
    virtual ~KhoiNganh() = default;
    virtual bool duDieuKien(HocSinh hs) const = 0;

    void themThiSinh(HocSinh hs) {
        dsThiSinh.push_back(hs);
    }

    bool dangKy(HocSinh hs) const {
        return duDieuKien(hs);
    }
};

class KhoiNganhA : public KhoiNganh {
private:
    static constexpr float DIEM_PASS_TOTAL = 25.0f;
    static constexpr float DIEM_PASS = 7.0f;

public:
    bool duDieuKien(HocSinh hs) const override {
        float tong = 0;
        vector<string> mon = {"Toan", "Ly", "Hoa"};

        for (const string &m : mon) {
            float d = hs.getDiemMon(m);
            if (d < DIEM_PASS) return false;
            tong += d;
        }

        return tong >= DIEM_PASS_TOTAL;
    }
};

class KhoiNganhB : public KhoiNganh {
private:
    static constexpr float DIEM_PASS_TOTAL = 26.0f;
    static constexpr float DIEM_PASS = 7.0f;

public:
    bool duDieuKien(HocSinh hs) const override {
        float tong = 0;
        vector<string> mon = {"Toan", "Hoa", "Sinh"};

        for (const string &m : mon) {
            float d = hs.getDiemMon(m);
            if (d < DIEM_PASS) return false;
            tong += d;
        }

        return tong >= DIEM_PASS_TOTAL;
    }
};

class KhoiNganhC : public KhoiNganh {
private:
    static constexpr float DIEM_PASS_TOTAL = 24.0f;
    static constexpr float DIEM_PASS = 6.0f;

public:
    bool duDieuKien(HocSinh hs) const override {
        float tong = 0;
        vector<string> mon = {"Van", "Su", "Dia"};

        for (const string &m : mon) {
            float d = hs.getDiemMon(m);
            if (d < DIEM_PASS) return false;
            tong += d;
        }

        return tong >= DIEM_PASS_TOTAL;
    }
};

#endif
