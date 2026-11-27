// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class cDiem {
private:
    double x;   // hoành độ
    double y;   // tung độ

public:
    cDiem();                               // mặc định: gốc tọa độ (0, 0)
    cDiem(double hoanhDo, double tungDo);  // khởi tạo khi biết tọa độ

    void input();                              // nhập tọa độ
    void output() const;                       // xuất dạng (x, y)
    double khoangCach(const cDiem& d) const;   // khoảng cách từ điểm này tới điểm d
};

cDiem::cDiem() : x(0), y(0) {}

cDiem::cDiem(double hoanhDo, double tungDo) : x(hoanhDo), y(tungDo) {}

// Nhập hoành độ và tung độ
void cDiem::input() {
    cout << "  Nhap hoanh do x: ";
    cin >> x;
    cout << "  Nhap tung do y: ";
    cin >> y;
}

// Xuất tọa độ dạng (x, y)
void cDiem::output() const {
    cout << "(" << x << ", " << y << ")";
}

// Khoảng cách AB = sqrt((xA - xB)^2 + (yA - yB)^2)
double cDiem::khoangCach(const cDiem& d) const {
    double dx = x - d.x;
    double dy = y - d.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cout << fixed << setprecision(2);   // in số thực với 2 chữ số thập phân

    cout << "===== 1. Khoi tao diem (mac dinh va co tham so) =====\n";
    cDiem goc;          // (0, 0)
    cDiem m(3, 4);
    cout << "O = "; goc.output(); cout << ", M = "; m.output(); cout << "\n";
    cout << "Khoang cach OM = " << goc.khoangCach(m) << "\n";

    cout << "\n===== 2. Nhap toa do 2 diem =====\n";
    cDiem a, b;
    cout << "Diem A:\n";
    a.input();
    cout << "Diem B:\n";
    b.input();
    cout << "A = "; a.output(); cout << ", B = "; b.output(); cout << "\n";

    cout << "\n===== 3. Tinh khoang cach giua 2 diem =====\n";
    cout << "Khoang cach AB = " << a.khoangCach(b) << "\n";

    return 0;
}
