// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979;

class cDiem {
private:
    double x;   // hoành độ
    double y;   // tung độ

public:
    cDiem();                               // mặc định: gốc tọa độ (0, 0)
    cDiem(double hoanhDo, double tungDo);  // khởi tạo khi biết tọa độ

    void input();           // nhập tọa độ
    void output() const;    // xuất dạng (x, y)
};

class cDuongTron {
private:
    cDiem tam;          // tâm đường tròn là một đối tượng cDiem
    double banKinh;

public:
    cDuongTron();                               // mặc định: tâm (0, 0), bán kính 1
    cDuongTron(const cDiem& tamDT, double r);   // khởi tạo khi biết tâm và bán kính

    void input();               // nhập tâm và bán kính
    void output() const;        // xuất thông tin đường tròn
    double dienTich() const;    // S = PI * r^2
    double chuVi() const;       // C = 2 * PI * r
};

// ===== Cài đặt cDiem =====

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

// ===== Cài đặt cDuongTron =====

// Mặc định: tâm là gốc tọa độ, bán kính 1
cDuongTron::cDuongTron() : tam(), banKinh(1) {}

// Bán kính phải > 0; nếu không hợp lệ thì dùng bán kính 1
cDuongTron::cDuongTron(const cDiem& tamDT, double r) : tam(tamDT), banKinh(r) {
    if (banKinh <= 0) {
        cout << "[Canh bao] Ban kinh phai > 0 -> tu dong gan ban kinh = 1\n";
        banKinh = 1;
    }
}

// Nhập tâm (gọi input của cDiem) và bán kính; bán kính <= 0 thì nhập lại
void cDuongTron::input() {
    cout << "Nhap toa do tam:\n";
    tam.input();
    cout << "Nhap ban kinh: ";
    cin >> banKinh;
    while (banKinh <= 0 && cin) {   // dừng nếu cin lỗi để không lặp vô hạn
        cout << "Ban kinh phai > 0, nhap lai: ";
        cin >> banKinh;
    }
    if (banKinh <= 0)
        banKinh = 1;                // phòng trường hợp nhập lỗi
}

// Xuất tâm và bán kính
void cDuongTron::output() const {
    cout << "Duong tron tam ";
    tam.output();
    cout << ", ban kinh " << banKinh;
}

// Diện tích hình tròn
double cDuongTron::dienTich() const {
    return PI * banKinh * banKinh;
}

// Chu vi đường tròn
double cDuongTron::chuVi() const {
    return 2 * PI * banKinh;
}

int main() {
    cout << fixed << setprecision(2);   // in số thực với 2 chữ số thập phân

    cout << "===== 1. Khoi tao duong tron (mac dinh va co tham so) =====\n";
    cDuongTron dt1;                      // tâm (0, 0), bán kính 1
    cDuongTron dt2(cDiem(1, 1), 2.5);    // tâm (1, 1), bán kính 2.5
    dt1.output(); cout << "\n";
    dt2.output(); cout << "\n";

    cout << "\n===== 2. Nhap duong tron tu ban phim =====\n";
    cDuongTron dt;
    dt.input();
    cout << "Vua nhap: "; dt.output(); cout << "\n";

    cout << "\n===== 3. Tinh dien tich =====\n";
    cout << "Dien tich S = PI * r^2 = " << dt.dienTich() << "\n";

    cout << "\n===== 4. Tinh chu vi =====\n";
    cout << "Chu vi C = 2 * PI * r = " << dt.chuVi() << "\n";

    return 0;
}
