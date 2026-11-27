// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#define _CRT_SECURE_NO_WARNINGS   // để Visual Studio không báo lỗi khi dùng localtime
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class cHocSinh {
private:
    string ma;
    string hoTen;
    bool gioiTinh;   // true: Nam, false: Nữ
    int namSinh;
    float dtb;       // điểm trung bình

public:
    cHocSinh();                                       // khởi tạo mặc định
    cHocSinh(const string& maHS, const string& ten,
             bool laNam, int nam, float diem);        // khởi tạo khi biết đủ thông tin

    void input();              // nhập từ bàn phím
    void output() const;       // xuất ra màn hình

    string getHoTen() const;   // lấy họ tên
    float getDTB() const;      // lấy điểm trung bình
    int getTuoi() const;       // tuổi = năm hiện tại - năm sinh
};

// Khởi tạo mặc định
cHocSinh::cHocSinh() : ma(""), hoTen(""), gioiTinh(true), namSinh(2000), dtb(0) {}

// Khởi tạo khi biết đầy đủ thông tin
cHocSinh::cHocSinh(const string& maHS, const string& ten, bool laNam, int nam, float diem)
    : ma(maHS), hoTen(ten), gioiTinh(laNam), namSinh(nam), dtb(diem) {}

// Nhập thông tin; họ tên dùng getline để nhận cả khoảng trắng
void cHocSinh::input() {
    cout << "Nhap ma hoc sinh: ";
    cin >> ma;
    cin.ignore(1000, '\n');     // bỏ ký tự xuống dòng còn sót lại trước khi getline
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
    int gt = 1;
    cin >> gt;
    gioiTinh = (gt == 1);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

// Xuất thông tin học sinh trên một dòng
void cHocSinh::output() const {
    cout << "Ma: " << ma
         << " | Ho ten: " << hoTen
         << " | Gioi tinh: " << (gioiTinh ? "Nam" : "Nu")
         << " | Nam sinh: " << namSinh
         << " | Tuoi: " << getTuoi()
         << " | DTB: " << dtb << "\n";
}

string cHocSinh::getHoTen() const {
    return hoTen;
}

float cHocSinh::getDTB() const {
    return dtb;
}

// Tuổi = năm hiện tại (lấy từ đồng hồ máy) - năm sinh
int cHocSinh::getTuoi() const {
    time_t bayGio = time(0);              // số giây tính từ 01/01/1970
    tm* thoiGian = localtime(&bayGio);    // đổi sang ngày giờ địa phương
    int namHienTai = thoiGian->tm_year + 1900;   // tm_year đếm từ năm 1900
    return namHienTai - namSinh;
}

int main() {
    cout << "===== 1. Hoc sinh mau (constructor co tham so) =====\n";
    cHocSinh mau("HS00", "Hoc Sinh Mau", true, 2010, 9.0f);
    mau.output();

    cout << "\n===== 2. Nhap thong tin 2 hoc sinh =====\n";
    cHocSinh hs1, hs2;
    cout << "--- Hoc sinh 1 ---\n";
    hs1.input();
    cout << "--- Hoc sinh 2 ---\n";
    hs2.input();

    cout << "\n===== 3. Thong tin 2 hoc sinh vua nhap =====\n";
    hs1.output();
    hs2.output();

    cout << "\n===== 4. Hoc sinh co diem trung binh cao hon =====\n";
    if (hs1.getDTB() > hs2.getDTB())
        cout << hs1.getHoTen() << " co DTB cao hon (" << hs1.getDTB() << " > " << hs2.getDTB() << ")\n";
    else if (hs1.getDTB() < hs2.getDTB())
        cout << hs2.getHoTen() << " co DTB cao hon (" << hs2.getDTB() << " > " << hs1.getDTB() << ")\n";
    else
        cout << "Hai hoc sinh co DTB bang nhau (" << hs1.getDTB() << ")\n";

    cout << "\n===== 5. Hoc sinh co tuoi nho hon =====\n";
    if (hs1.getTuoi() < hs2.getTuoi())
        cout << hs1.getHoTen() << " nho tuoi hon (" << hs1.getTuoi() << " < " << hs2.getTuoi() << " tuoi)\n";
    else if (hs1.getTuoi() > hs2.getTuoi())
        cout << hs2.getHoTen() << " nho tuoi hon (" << hs2.getTuoi() << " < " << hs1.getTuoi() << " tuoi)\n";
    else
        cout << "Hai hoc sinh bang tuoi (" << hs1.getTuoi() << " tuoi)\n";

    return 0;
}
