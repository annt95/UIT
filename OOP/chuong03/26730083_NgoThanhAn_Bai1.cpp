// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class cHocSinh {
private:
    string hoTen;
    float diemToan;
    float diemVan;

public:
    cHocSinh();                                          // khởi tạo mặc định
    cHocSinh(const string& ten, float toan, float van);  // khởi tạo khi biết đủ thông tin

    void input();              // nhập họ tên, điểm toán, điểm văn
    void output() const;       // xuất thông tin, điểm trung bình và xếp loại
    float tinhDTB() const;     // điểm trung bình = (toán + văn) / 2
    string xepLoai() const;    // Giỏi / Khá / Trung bình / Yếu
};

// Khởi tạo mặc định
cHocSinh::cHocSinh() : hoTen(""), diemToan(0), diemVan(0) {}

// Khởi tạo khi biết họ tên và 2 điểm
cHocSinh::cHocSinh(const string& ten, float toan, float van)
    : hoTen(ten), diemToan(toan), diemVan(van) {}

// Nhập thông tin; họ tên dùng getline để nhận cả khoảng trắng
void cHocSinh::input() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap diem toan: ";
    cin >> diemToan;
    cout << "Nhap diem van: ";
    cin >> diemVan;
}

// Điểm trung bình của 2 môn
float cHocSinh::tinhDTB() const {
    return (diemToan + diemVan) / 2;
}

// Xếp loại: Giỏi >= 8, Khá >= 6.5, Trung bình >= 5, còn lại là Yếu
string cHocSinh::xepLoai() const {
    float dtb = tinhDTB();
    if (dtb >= 8)
        return "Gioi";
    if (dtb >= 6.5)
        return "Kha";
    if (dtb >= 5)
        return "Trung binh";
    return "Yeu";
}

// Xuất thông tin học sinh trên một dòng
void cHocSinh::output() const {
    cout << "Ho ten: " << hoTen
         << " | Toan: " << diemToan
         << " | Van: " << diemVan
         << " | DTB: " << tinhDTB()
         << " | Xep loai: " << xepLoai() << "\n";
}

int main() {
    cout << fixed << setprecision(2);   // in số thực với 2 chữ số thập phân

    cout << "===== 1. Nhap thong tin hoc sinh =====\n";
    cHocSinh hs;
    hs.input();

    cout << "\n===== 2. Tinh diem trung binh =====\n";
    cout << "Diem trung binh: " << hs.tinhDTB() << "\n";

    cout << "\n===== 3. Xep loai =====\n";
    cout << "Xep loai: " << hs.xepLoai() << "\n";

    cout << "\n===== 4. Xuat ket qua =====\n";
    hs.output();

    cout << "\n===== 5. Minh hoa 4 muc xep loai (constructor co tham so) =====\n";
    cHocSinh a("Hoc sinh A", 9, 8);      // DTB 8.5  -> Gioi
    cHocSinh b("Hoc sinh B", 7, 6);      // DTB 6.5  -> Kha (đúng ngưỡng)
    cHocSinh c("Hoc sinh C", 5, 5);      // DTB 5.0  -> Trung binh (đúng ngưỡng)
    cHocSinh d("Hoc sinh D", 4, 5.5f);   // DTB 4.75 -> Yeu
    a.output();
    b.output();
    c.output();
    d.output();

    return 0;
}
