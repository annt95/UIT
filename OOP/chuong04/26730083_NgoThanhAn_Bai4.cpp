// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
using namespace std;

// Đa thức P(x) = a_n x^n + ... + a_1 x + a_0
class cDaThuc {
private:
    int bac;          // bậc n của đa thức
    double* heSo;     // heSo[i] là hệ số của x^i (i = 0..bac), cấp phát động bac + 1 phần tử

    void capPhat(int n);     // giải phóng vùng nhớ cũ, cấp phát n + 1 hệ số bằng 0
    void chuanHoaBac();      // bỏ hệ số 0 ở bậc cao nhất (vd 0x^2 + 3 -> bậc 0)

public:
    cDaThuc();                                 // đa thức bậc 0: P(x) = 0
    cDaThuc(int n);                            // đa thức bậc n, các hệ số bằng 0
    cDaThuc(const cDaThuc& other);             // constructor sao chép (sao chép sâu)
    ~cDaThuc();                                // destructor: giải phóng bộ nhớ
    cDaThuc& operator=(const cDaThuc& other);  // toán tử gán (sao chép sâu)

    int getBac() const;                        // lấy bậc
    bool setHeSo(int i, double giaTri);        // gán hệ số của x^i; false nếu i ngoài [0, bac]

    void input();                              // nhập bậc và các hệ số
    void output() const;                       // xuất dạng 2x^3 - x + 5
    double tinhGiaTri(double x) const;         // giá trị P(x)
    cDaThuc cong(const cDaThuc& q) const;      // this + q
    cDaThuc tru(const cDaThuc& q) const;       // this - q
};

// Giải phóng vùng nhớ cũ rồi cấp phát n + 1 hệ số mới
void cDaThuc::capPhat(int n) {
    delete[] heSo;                  // delete[] với nullptr vẫn an toàn
    bac = n;
    heSo = new double[bac + 1]();   // () để mọi hệ số ban đầu bằng 0
}

// Giảm bậc khi hệ số bậc cao nhất bằng 0 (vùng nhớ thừa vẫn được giải phóng ở destructor)
void cDaThuc::chuanHoaBac() {
    while (bac > 0 && heSo[bac] == 0)
        bac--;
}

cDaThuc::cDaThuc() : bac(0), heSo(nullptr) {
    capPhat(0);
}

// Bậc âm không hợp lệ nên dùng bậc 0
cDaThuc::cDaThuc(int n) : bac(0), heSo(nullptr) {
    if (n < 0)
        n = 0;
    capPhat(n);
}

// Constructor sao chép: cấp phát mảng hệ số RIÊNG rồi chép từng hệ số
cDaThuc::cDaThuc(const cDaThuc& other) : bac(0), heSo(nullptr) {
    capPhat(other.bac);
    for (int i = 0; i <= bac; i++)
        heSo[i] = other.heSo[i];
}

cDaThuc::~cDaThuc() {
    delete[] heSo;
}

// Toán tử gán: bỏ mảng cũ, cấp phát mảng mới rồi chép từ other
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {           // tránh tự gán
        capPhat(other.bac);
        for (int i = 0; i <= bac; i++)
            heSo[i] = other.heSo[i];
    }
    return *this;
}

int cDaThuc::getBac() const {
    return bac;
}

// Chỉ gán khi chỉ số i hợp lệ
bool cDaThuc::setHeSo(int i, double giaTri) {
    if (i < 0 || i > bac)
        return false;
    heSo[i] = giaTri;
    return true;
}

// Nhập bậc n (>= 0), rồi nhập hệ số từ bậc cao xuống bậc thấp như cách viết P(x)
void cDaThuc::input() {
    int n = 0;
    cout << "  Nhap bac n (>= 0): ";
    cin >> n;
    while (n < 0 && cin) {          // dừng nếu cin lỗi để không lặp vô hạn
        cout << "  Bac phai >= 0, nhap lai: ";
        cin >> n;
    }
    if (n < 0)
        n = 0;
    capPhat(n);
    for (int i = bac; i >= 0; i--) {
        cout << "  He so cua x^" << i << ": ";
        cin >> heSo[i];
    }
    chuanHoaBac();
}

// Xuất từ bậc cao xuống bậc thấp, bỏ các hạng tử có hệ số 0
void cDaThuc::output() const {
    bool daIn = false;                       // đã in hạng tử nào chưa
    for (int i = bac; i >= 0; i--) {
        double a = heSo[i];
        if (a == 0)
            continue;
        if (daIn)
            cout << (a < 0 ? " - " : " + ");  // dấu giữa các hạng tử
        else if (a < 0)
            cout << "-";                      // hạng tử đầu tiên âm
        double triTuyetDoi = (a < 0) ? -a : a;
        if (triTuyetDoi != 1 || i == 0)
            cout << triTuyetDoi;              // hệ số 1 thì không viết (trừ hằng số)
        if (i > 0)
            cout << "x";
        if (i > 1)
            cout << "^" << i;
        daIn = true;
    }
    if (!daIn)
        cout << 0;                           // mọi hệ số đều bằng 0
}

// P(x) = tổng heSo[i] * x^i, với luyThua giữ giá trị x^i
double cDaThuc::tinhGiaTri(double x) const {
    double kq = 0;
    double luyThua = 1;
    for (int i = 0; i <= bac; i++) {
        kq = kq + heSo[i] * luyThua;
        luyThua = luyThua * x;
    }
    return kq;
}

// Cộng các hệ số cùng bậc; bậc của tổng tối đa bằng bậc lớn hơn
cDaThuc cDaThuc::cong(const cDaThuc& q) const {
    int n = (bac > q.bac) ? bac : q.bac;
    cDaThuc kq(n);                           // các hệ số ban đầu bằng 0
    for (int i = 0; i <= bac; i++)
        kq.heSo[i] = kq.heSo[i] + heSo[i];
    for (int i = 0; i <= q.bac; i++)
        kq.heSo[i] = kq.heSo[i] + q.heSo[i];
    kq.chuanHoaBac();
    return kq;
}

// Trừ các hệ số cùng bậc
cDaThuc cDaThuc::tru(const cDaThuc& q) const {
    int n = (bac > q.bac) ? bac : q.bac;
    cDaThuc kq(n);
    for (int i = 0; i <= bac; i++)
        kq.heSo[i] = kq.heSo[i] + heSo[i];
    for (int i = 0; i <= q.bac; i++)
        kq.heSo[i] = kq.heSo[i] - q.heSo[i];
    kq.chuanHoaBac();
    return kq;
}

int main() {
    cout << "===== 1. Khoi tao da thuc bac 0 va bac n =====\n";
    cDaThuc p0;             // bậc 0: P(x) = 0
    cDaThuc p3(3);          // bậc 3, các hệ số bằng 0
    p3.setHeSo(3, 2);       // 2x^3
    p3.setHeSo(1, -1);      // -x
    p3.setHeSo(0, 5);       // +5
    cout << "cDaThuc()               : ";
    p0.output();
    cout << "  (bac " << p0.getBac() << ")\n";
    cout << "cDaThuc(3) + gan he so  : ";
    p3.output();
    cout << "  (bac " << p3.getBac() << ")\n";

    cout << "\n===== 2. Nhap 2 da thuc =====\n";
    cDaThuc p, q;
    cout << "Da thuc P(x):\n";
    p.input();
    cout << "Da thuc Q(x):\n";
    q.input();

    cout << "\n===== 3. Xuat 2 da thuc =====\n";
    cout << "P(x) = ";
    p.output();
    cout << "\nQ(x) = ";
    q.output();
    cout << "\n";

    cout << "\n===== 4. Tinh gia tri da thuc khi biet x =====\n";
    double x = 0;
    cout << "Nhap x: ";
    cin >> x;
    cout << "P(" << x << ") = " << p.tinhGiaTri(x) << "\n";
    cout << "Q(" << x << ") = " << q.tinhGiaTri(x) << "\n";

    cout << "\n===== 5. Tong hai da thuc =====\n";
    cDaThuc tong = p.cong(q);
    cout << "P(x) + Q(x) = ";
    tong.output();
    cout << "  (bac " << tong.getBac() << ")\n";

    cout << "\n===== 6. Hieu hai da thuc =====\n";
    cDaThuc hieu = p.tru(q);
    cout << "P(x) - Q(x) = ";
    hieu.output();
    cout << "  (bac " << hieu.getBac() << ")\n";

    return 0;
}
