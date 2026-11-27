// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
using namespace std;

class cPhanSo {
private:
    int tu;   // tử số
    int mau;  // mẫu số (luôn khác 0 và luôn dương sau khi chuẩn hóa)

    static int ucln(int a, int b);   // ước chung lớn nhất, dùng để rút gọn
    void chuanHoa();                 // đưa dấu âm lên tử và rút gọn

public:
    cPhanSo();                       // khởi tạo mặc định: 0/1
    cPhanSo(int tuSo, int mauSo);    // khởi tạo khi biết tử và mẫu
    cPhanSo(int soNguyen);           // khởi tạo từ một số nguyên n -> n/1

    void input();                    // nhập phân số từ bàn phím
    void output() const;             // xuất phân số ra màn hình
    bool isZero() const;             // kiểm tra phân số có bằng 0 không

    cPhanSo tong(const cPhanSo& ps) const;     // this + ps
    cPhanSo hieu(const cPhanSo& ps) const;     // this - ps
    cPhanSo tich(const cPhanSo& ps) const;     // this * ps
    cPhanSo thuong(const cPhanSo& ps) const;   // this : ps
};

// Tìm ước chung lớn nhất của |a| và |b| bằng thuật toán Euclid
int cPhanSo::ucln(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int du = a % b;
        a = b;
        b = du;
    }
    return a;
}

// Chuẩn hóa: mẫu luôn dương (dấu âm chuyển lên tử), sau đó rút gọn
void cPhanSo::chuanHoa() {
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    int u = ucln(tu, mau);
    if (u > 1) {
        tu = tu / u;
        mau = mau / u;
    }
}

// Khởi tạo mặc định: tử = 0, mẫu = 1
cPhanSo::cPhanSo() {
    tu = 0;
    mau = 1;
}

// Khởi tạo khi biết tử và mẫu; mẫu = 0 không hợp lệ nên gán mẫu = 1
cPhanSo::cPhanSo(int tuSo, int mauSo) {
    if (mauSo == 0) {
        cout << "[Canh bao] Mau so bang 0 khong hop le -> tu dong gan mau = 1\n";
        mauSo = 1;
    }
    tu = tuSo;
    mau = mauSo;
    chuanHoa();
}

// Khởi tạo từ một số nguyên: n = n/1
cPhanSo::cPhanSo(int soNguyen) {
    tu = soNguyen;
    mau = 1;
}

// Nhập tử và mẫu; nếu mẫu = 0 thì bắt nhập lại
void cPhanSo::input() {
    cout << "Nhap tu so: ";
    cin >> tu;
    cout << "Nhap mau so: ";
    cin >> mau;
    while (mau == 0 && cin) {   // dừng nếu cin lỗi (nhập chữ, hết dữ liệu) để không lặp vô hạn
        cout << "Mau so phai khac 0, nhap lai: ";
        cin >> mau;
    }
    if (mau == 0)
        mau = 1;                // phòng trường hợp nhập lỗi
    chuanHoa();
}

// Xuất dạng tu/mau; nếu mẫu = 1 thì chỉ in tử (số nguyên)
void cPhanSo::output() const {
    if (mau == 1)
        cout << tu;
    else
        cout << tu << "/" << mau;
}

// Phân số bằng 0 khi tử bằng 0
bool cPhanSo::isZero() const {
    return tu == 0;
}

// a/b + c/d = (a*d + c*b) / (b*d)
cPhanSo cPhanSo::tong(const cPhanSo& ps) const {
    return cPhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau);
}

// a/b - c/d = (a*d - c*b) / (b*d)
cPhanSo cPhanSo::hieu(const cPhanSo& ps) const {
    return cPhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau);
}

// a/b * c/d = (a*c) / (b*d)
cPhanSo cPhanSo::tich(const cPhanSo& ps) const {
    return cPhanSo(tu * ps.tu, mau * ps.mau);
}

// a/b : c/d = (a*d) / (b*c); không chia được cho phân số 0
cPhanSo cPhanSo::thuong(const cPhanSo& ps) const {
    if (ps.isZero()) {
        cout << "[Loi] Khong the chia cho phan so 0 -> tra ve 0\n";
        return cPhanSo();
    }
    return cPhanSo(tu * ps.mau, mau * ps.tu);   // constructor tự xử lý mẫu âm và rút gọn
}

int main() {
    cout << "===== 1. Cac cach khoi tao phan so =====\n";
    cPhanSo ps1;          // mặc định
    cPhanSo ps2(3, -6);   // biết tử, mẫu (mẫu âm -> -1/2)
    cPhanSo ps3(7);       // từ số nguyên
    cout << "cPhanSo()      = "; ps1.output(); cout << "\n";
    cout << "cPhanSo(3, -6) = "; ps2.output(); cout << "\n";
    cout << "cPhanSo(7)     = "; ps3.output(); cout << "\n";
    cout << "cPhanSo(2, 0)  : ";
    cPhanSo ps4(2, 0);    // mẫu = 0 -> cảnh báo và gán mẫu = 1
    cout << "cPhanSo(2, 0)  = "; ps4.output(); cout << "\n";

    cout << "\n===== 2. Khoi tao phan so a tu tu, mau do nguoi dung nhap =====\n";
    int t = 0, m = 1;
    cout << "Nhap tu so cua a: ";
    cin >> t;
    cout << "Nhap mau so cua a: ";
    cin >> m;
    cPhanSo a(t, m);      // khởi tạo bằng constructor có tham số
    cout << "a = "; a.output(); cout << "\n";

    cout << "\n===== 3. Nhap phan so b tu ban phim =====\n";
    cPhanSo b;
    b.input();            // nhập bằng phương thức input()
    cout << "b = "; b.output(); cout << "\n";

    cout << "\n===== 4. Tong a + b =====\n";
    cPhanSo tong = a.tong(b);
    cout << "a + b = "; tong.output(); cout << "\n";

    cout << "\n===== 5. Hieu, tich, thuong =====\n";
    cout << "a - b = "; a.hieu(b).output(); cout << "\n";
    cout << "a * b = "; a.tich(b).output(); cout << "\n";
    if (b.isZero()) {
        cout << "a : b -> khong chia duoc vi b = 0\n";
    } else {
        cout << "a : b = "; a.thuong(b).output(); cout << "\n";
    }

    cout << "\n===== 6. Xu ly chia cho phan so 0 =====\n";
    cPhanSo kq = a.thuong(ps1);   // ps1 = 0
    cout << "a : 0 = "; kq.output(); cout << "\n";

    return 0;
}
