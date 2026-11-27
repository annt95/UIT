// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
using namespace std;

// Đơn thức P(x) = a * x^b
class cDonThuc {
private:
    double heSo;   // hệ số a
    int soMu;      // số mũ b (luôn >= 0)

public:
    cDonThuc();                    // mặc định: đơn thức 0 (a = 0, b = 0)
    cDonThuc(double a, int b);     // tạo lập khi biết hệ số và số mũ

    void input();                  // nhập hệ số, số mũ
    void output() const;           // xuất dạng ax^b

    double getHeSo() const;        // lấy hệ số
    int getSoMu() const;           // lấy số mũ
    void setHeSo(double a);        // thay đổi hệ số
    bool setSoMu(int b);           // thay đổi số mũ; trả về false nếu b < 0 (không hợp lệ)

    double tinhGiaTri(double x) const;          // giá trị P(x) = a * x^b
    cDonThuc daoHam() const;                    // (ax^b)' = (a*b) x^(b-1)
    bool isCungBac(const cDonThuc& d) const;    // hai đơn thức có cùng số mũ không

    // Hàm bạn: không phải phương thức của lớp nhưng được truy cập trực tiếp heSo, soMu
    friend cDonThuc tong(const cDonThuc& d1, const cDonThuc& d2);
};

cDonThuc::cDonThuc() : heSo(0), soMu(0) {}

// Số mũ âm không hợp lệ với đơn thức nên gán số mũ = 0
cDonThuc::cDonThuc(double a, int b) : heSo(a), soMu(b) {
    if (soMu < 0) {
        cout << "[Canh bao] So mu am khong hop le -> tu dong gan so mu = 0\n";
        soMu = 0;
    }
}

// Nhập hệ số và số mũ; số mũ âm thì bắt nhập lại
void cDonThuc::input() {
    cout << "  Nhap he so a: ";
    cin >> heSo;
    cout << "  Nhap so mu b (>= 0): ";
    cin >> soMu;
    while (soMu < 0 && cin) {   // dừng nếu cin lỗi để không lặp vô hạn
        cout << "  So mu phai >= 0, nhap lai: ";
        cin >> soMu;
    }
    if (soMu < 0)
        soMu = 0;               // phòng trường hợp nhập lỗi
}

// Xuất gọn: 3x^2, -x, 2x, 5, 0 ...
void cDonThuc::output() const {
    if (heSo == 0) {            // hệ số 0 thì đơn thức bằng 0
        cout << 0;
        return;
    }
    if (soMu == 0) {            // x^0 = 1 nên chỉ còn hệ số
        cout << heSo;
        return;
    }
    if (heSo == -1)
        cout << "-";            // -1x viết là -x
    else if (heSo != 1)
        cout << heSo;           // 1x viết là x
    cout << "x";
    if (soMu > 1)
        cout << "^" << soMu;
}

double cDonThuc::getHeSo() const {
    return heSo;
}

int cDonThuc::getSoMu() const {
    return soMu;
}

void cDonThuc::setHeSo(double a) {
    heSo = a;
}

// Chỉ cập nhật khi số mũ hợp lệ (>= 0)
bool cDonThuc::setSoMu(int b) {
    if (b < 0)
        return false;
    soMu = b;
    return true;
}

// Tính x^b bằng vòng lặp rồi nhân với hệ số
double cDonThuc::tinhGiaTri(double x) const {
    double luyThua = 1;
    for (int i = 0; i < soMu; i++)
        luyThua = luyThua * x;
    return heSo * luyThua;
}

// Đạo hàm của hằng số (b = 0) bằng 0
cDonThuc cDonThuc::daoHam() const {
    if (soMu == 0)
        return cDonThuc();
    return cDonThuc(heSo * soMu, soMu - 1);
}

bool cDonThuc::isCungBac(const cDonThuc& d) const {
    return soMu == d.soMu;
}

// Hàm bạn: ax^b + cx^b = (a + c)x^b; khác bậc thì không cộng thành 1 đơn thức được
cDonThuc tong(const cDonThuc& d1, const cDonThuc& d2) {
    if (d1.soMu != d2.soMu) {
        cout << "[Loi] Hai don thuc khong cung bac -> tra ve don thuc 0\n";
        return cDonThuc();
    }
    return cDonThuc(d1.heSo + d2.heSo, d1.soMu);
}

int main() {
    cout << "===== 1. Tao lap don thuc khi biet he so va so mu =====\n";
    cDonThuc d(3, 2);
    cout << "cDonThuc(3, 2) = ";
    d.output();
    cout << "\n";

    cout << "\n===== 2. Thay doi thong tin don thuc (get / set) =====\n";
    d.setHeSo(-1);
    d.setSoMu(5);
    cout << "Sau setHeSo(-1), setSoMu(5): d = ";
    d.output();
    cout << "  (he so " << d.getHeSo() << ", so mu " << d.getSoMu() << ")\n";
    if (!d.setSoMu(-2))
        cout << "setSoMu(-2) bi tu choi vi so mu am\n";

    cout << "\n===== 3. Nhap 2 don thuc =====\n";
    cDonThuc d1, d2;
    cout << "Don thuc d1:\n";
    d1.input();
    cout << "Don thuc d2:\n";
    d2.input();

    cout << "\n===== 4. Xuat 2 don thuc =====\n";
    cout << "d1 = ";
    d1.output();
    cout << "\nd2 = ";
    d2.output();
    cout << "\n";

    cout << "\n===== 5. Tinh gia tri don thuc khi biet x =====\n";
    double x = 0;
    cout << "Nhap x: ";
    cin >> x;
    cout << "d1(" << x << ") = " << d1.tinhGiaTri(x) << "\n";
    cout << "d2(" << x << ") = " << d2.tinhGiaTri(x) << "\n";

    cout << "\n===== 6. Dao ham cua don thuc =====\n";
    cout << "d1' = ";
    d1.daoHam().output();
    cout << "\nd2' = ";
    d2.daoHam().output();
    cout << "\n";

    cout << "\n===== 7. Tong 2 don thuc cung bac (ham ban) =====\n";
    if (d1.isCungBac(d2)) {
        cout << "d1 + d2 = ";
        tong(d1, d2).output();
        cout << "\n";
    } else {
        cout << "d1 va d2 khong cung bac nen khong cong thanh 1 don thuc duoc\n";
    }

    return 0;
}
