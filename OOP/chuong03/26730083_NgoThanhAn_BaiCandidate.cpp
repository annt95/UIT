// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#define _CRT_SECURE_NO_WARNINGS   // để Visual Studio không báo lỗi khi dùng localtime
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class cCandidate {
private:
    string maSo;
    string hoTen;
    bool gioiTinh;   // true: Nam, false: Nữ
    int namSinh;
    float dtb;       // điểm trung bình

public:
    cCandidate();                                    // tạo lập mặc định
    cCandidate(const string& ma, const string& ten,
               bool laNam, int nam, float diem);     // tạo lập khi biết đủ thông tin
    cCandidate(const cCandidate& c);                 // tạo lập từ thí sinh đã có (sao chép)
    ~cCandidate();                                   // hủy đối tượng

    void input();            // nhập từ bàn phím
    void output() const;     // xuất ra màn hình
    int getTuoi() const;     // tuổi = năm hiện tại - năm sinh

    // operator>> nhận cCandidate& (KHÔNG const) vì phải ghi dữ liệu vào c
    friend istream& operator>>(istream& is, cCandidate& c);
    // operator<< chỉ đọc dữ liệu nên nhận const cCandidate&
    friend ostream& operator<<(ostream& os, const cCandidate& c);
};

// Tạo lập mặc định
cCandidate::cCandidate() : maSo(""), hoTen(""), gioiTinh(true), namSinh(2000), dtb(0) {}

// Tạo lập khi biết đầy đủ thông tin
cCandidate::cCandidate(const string& ma, const string& ten, bool laNam, int nam, float diem)
    : maSo(ma), hoTen(ten), gioiTinh(laNam), namSinh(nam), dtb(diem) {}

// Tạo lập từ một thí sinh đã có: chép từng thuộc tính của c sang đối tượng mới
cCandidate::cCandidate(const cCandidate& c)
    : maSo(c.maSo), hoTen(c.hoTen), gioiTinh(c.gioiTinh), namSinh(c.namSinh), dtb(c.dtb) {}

// Hủy: lớp không cấp phát động (string tự giải phóng) nên không cần làm gì
cCandidate::~cCandidate() {}

// Nhập thí sinh từ luồng is; họ tên dùng getline để nhận cả khoảng trắng
istream& operator>>(istream& is, cCandidate& c) {
    cout << "Nhap ma so: ";
    is >> c.maSo;
    is.ignore(1000, '\n');      // bỏ ký tự xuống dòng còn sót lại trước khi getline
    cout << "Nhap ho ten: ";
    getline(is, c.hoTen);
    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
    int gt = 1;
    is >> gt;
    c.gioiTinh = (gt == 1);
    cout << "Nhap nam sinh: ";
    is >> c.namSinh;
    cout << "Nhap diem trung binh: ";
    is >> c.dtb;
    return is;
}

// Xuất thí sinh ra luồng os trên một dòng
ostream& operator<<(ostream& os, const cCandidate& c) {
    os << "Ma so: " << c.maSo
       << " | Ho ten: " << c.hoTen
       << " | Gioi tinh: " << (c.gioiTinh ? "Nam" : "Nu")
       << " | Nam sinh: " << c.namSinh
       << " | DTB: " << c.dtb;
    return os;
}

// Nhập từ bàn phím: dùng lại operator>>
void cCandidate::input() {
    cin >> *this;
}

// Xuất ra màn hình: dùng lại operator<<
void cCandidate::output() const {
    cout << *this << "\n";
}

// Tuổi = năm hiện tại (lấy từ đồng hồ máy) - năm sinh
int cCandidate::getTuoi() const {
    time_t bayGio = time(0);              // số giây tính từ 01/01/1970
    tm* thoiGian = localtime(&bayGio);    // đổi sang ngày giờ địa phương
    int namHienTai = thoiGian->tm_year + 1900;   // tm_year đếm từ năm 1900
    return namHienTai - namSinh;
}

int main() {
    cout << "===== 1. Tao lap thi sinh mac dinh =====\n";
    cCandidate c1;
    c1.output();

    cout << "\n===== 2. Tao lap thi sinh khi biet day du thong tin =====\n";
    cCandidate c2("TS001", "Nguyen Van An", true, 2005, 8.5f);
    c2.output();

    cout << "\n===== 3. Tao lap thi sinh tu thi sinh da co (constructor sao chep) =====\n";
    cCandidate c3(c2);
    c3.output();

    cout << "\n===== 4. Nhap thong tin thi sinh tu ban phim (input) =====\n";
    cCandidate c4;
    c4.input();

    cout << "\n===== 5. Xuat thong tin thi sinh ra man hinh (output) =====\n";
    c4.output();

    cout << "\n===== 6. Cho biet tuoi cua thi sinh =====\n";
    cout << "Tuoi cua thi sinh TS001: " << c2.getTuoi() << "\n";
    cout << "Tuoi cua thi sinh vua nhap: " << c4.getTuoi() << "\n";

    cout << "\n===== 7. Nhap / xuat bang operator>> va operator<< =====\n";
    cCandidate c5;
    cin >> c5;
    cout << "Thi sinh vua nhap: " << c5 << "\n";

    return 0;
}
