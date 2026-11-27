// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std;

class cPhanSo {
private:
    int tu;    // tử số
    int mau;   // mẫu số (luôn dương sau khi chuẩn hóa)

    static int ucln(int a, int b);   // ước chung lớn nhất, dùng để rút gọn
    void chuanHoa();                 // đưa dấu âm lên tử và rút gọn

public:
    cPhanSo();                       // 0/1 – bắt buộc phải có để tạo được mảng cPhanSo
    cPhanSo(int tuSo, int mauSo);    // khởi tạo khi biết tử và mẫu

    void input();            // nhập phân số
    void output() const;     // xuất phân số

    friend class arrPhanSo;  // lớp bạn: arrPhanSo được truy cập trực tiếp tu, mau
};

class arrPhanSo {
private:
    cPhanSo* ds;   // mảng động các đối tượng cPhanSo
    int n;         // số phân số

    void capPhat(int soPhanTu);                               // giải phóng cũ, cấp phát mới
    static bool nhoHon(const cPhanSo& p, const cPhanSo& q);   // p < q ?
    static bool laSoNguyenTo(int x);                          // x có phải số nguyên tố không

public:
    arrPhanSo();                                   // danh sách rỗng
    arrPhanSo(const arrPhanSo& other);             // constructor sao chép (sao chép sâu)
    ~arrPhanSo();                                  // destructor: giải phóng bộ nhớ
    arrPhanSo& operator=(const arrPhanSo& other);  // toán tử gán (sao chép sâu)

    void input();                      // 1. nhập các phân số
    void output() const;               // 2. xuất danh sách phân số
    void taoNgauNhien(int soPhanTu);   // 3. tạo n phân số ngẫu nhiên
    bool timMax(cPhanSo& kq) const;    // 4. tìm phân số lớn nhất; false nếu danh sách rỗng
    int demTuNguyenTo() const;         // 5. đếm phân số có tử là số nguyên tố
    void sapXepTang();                 // 6. sắp xếp tăng dần
};

// ===== Cài đặt cPhanSo =====

// Ước chung lớn nhất của |a| và |b| (thuật toán Euclid)
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

// Mẫu luôn dương (dấu âm chuyển lên tử), sau đó rút gọn tối giản
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

cPhanSo::cPhanSo() : tu(0), mau(1) {}

// Mẫu = 0 không hợp lệ nên gán mẫu = 1
cPhanSo::cPhanSo(int tuSo, int mauSo) : tu(tuSo), mau(mauSo) {
    if (mau == 0) {
        cout << "[Canh bao] Mau so bang 0 khong hop le -> tu dong gan mau = 1\n";
        mau = 1;
    }
    chuanHoa();
}

// Nhập tử và mẫu; mẫu = 0 thì bắt nhập lại
void cPhanSo::input() {
    cout << "  Nhap tu so: ";
    cin >> tu;
    cout << "  Nhap mau so: ";
    cin >> mau;
    while (mau == 0 && cin) {   // dừng nếu cin lỗi để không lặp vô hạn
        cout << "  Mau so phai khac 0, nhap lai: ";
        cin >> mau;
    }
    if (mau == 0)
        mau = 1;                // phòng trường hợp nhập lỗi
    chuanHoa();
}

// Xuất dạng tu/mau; mẫu = 1 thì chỉ in tử
void cPhanSo::output() const {
    if (mau == 1)
        cout << tu;
    else
        cout << tu << "/" << mau;
}

// ===== Cài đặt arrPhanSo =====

// Giải phóng vùng nhớ cũ rồi cấp phát mảng mới gồm soPhanTu phân số
void arrPhanSo::capPhat(int soPhanTu) {
    delete[] ds;                // delete[] với nullptr vẫn an toàn
    if (soPhanTu <= 0) {
        ds = nullptr;
        n = 0;
    } else {
        n = soPhanTu;
        ds = new cPhanSo[n];    // new[] gọi constructor mặc định cho từng phần tử (mỗi phần tử = 0/1)
    }
}

arrPhanSo::arrPhanSo() : ds(nullptr), n(0) {}

// Constructor sao chép: cấp phát mảng RIÊNG rồi chép từng phân số
arrPhanSo::arrPhanSo(const arrPhanSo& other) : ds(nullptr), n(0) {
    capPhat(other.n);
    for (int i = 0; i < n; i++)
        ds[i] = other.ds[i];
}

arrPhanSo::~arrPhanSo() {
    delete[] ds;                // gọi destructor cho từng phần tử rồi trả vùng nhớ
}

// Toán tử gán: bỏ mảng cũ, cấp phát mảng mới rồi chép từ other
arrPhanSo& arrPhanSo::operator=(const arrPhanSo& other) {
    if (this != &other) {       // tránh tự gán
        capPhat(other.n);
        for (int i = 0; i < n; i++)
            ds[i] = other.ds[i];
    }
    return *this;
}

// So sánh p < q bằng nhân chéo: a/b < c/d  <=>  a*d < c*b (vì b, d > 0)
// Truy cập trực tiếp p.tu, p.mau được là nhờ arrPhanSo là lớp bạn của cPhanSo
bool arrPhanSo::nhoHon(const cPhanSo& p, const cPhanSo& q) {
    return p.tu * q.mau < q.tu * p.mau;
}

// Số nguyên tố: lớn hơn 1 và không chia hết cho số nào từ 2 đến căn bậc hai của nó
bool arrPhanSo::laSoNguyenTo(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// Nhập n (phải > 0) rồi nhập từng phân số
void arrPhanSo::input() {
    int soPhanTu = 0;
    cout << "Nhap so phan so n: ";
    cin >> soPhanTu;
    while (soPhanTu <= 0 && cin) {
        cout << "n phai > 0, nhap lai: ";
        cin >> soPhanTu;
    }
    capPhat(soPhanTu);
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ":\n";
        ds[i].input();
    }
}

// Xuất các phân số trên một dòng
void arrPhanSo::output() const {
    if (n == 0) {
        cout << "(danh sach rong)\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        ds[i].output();
        cout << "   ";
    }
    cout << "\n";
}

// Tạo n phân số ngẫu nhiên: tử trong [-10, 10], mẫu trong [1, 10] (không bao giờ bằng 0)
void arrPhanSo::taoNgauNhien(int soPhanTu) {
    capPhat(soPhanTu);
    for (int i = 0; i < n; i++) {
        int t = rand() % 21 - 10;
        int m = rand() % 10 + 1;
        ds[i] = cPhanSo(t, m);
    }
}

// Tìm phân số lớn nhất bằng cách so sánh lần lượt
bool arrPhanSo::timMax(cPhanSo& kq) const {
    if (n == 0)
        return false;
    kq = ds[0];
    for (int i = 1; i < n; i++)
        if (nhoHon(kq, ds[i]))
            kq = ds[i];
    return true;
}

// Phân số luôn ở dạng tối giản nên tử được xét sau khi rút gọn (vd 4/6 lưu là 2/3 -> tử 2)
int arrPhanSo::demTuNguyenTo() const {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (laSoNguyenTo(ds[i].tu))
            dem++;
    return dem;
}

// Sắp xếp tăng dần bằng thuật toán đổi chỗ trực tiếp (Interchange Sort)
void arrPhanSo::sapXepTang() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (nhoHon(ds[j], ds[i])) {
                cPhanSo tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
}

int main() {
    srand((unsigned int)time(0));   // khởi tạo bộ sinh số ngẫu nhiên MỘT lần

    cout << "===== 1. Nhap cac phan so =====\n";
    arrPhanSo ds;
    ds.input();

    cout << "\n===== 2. Xuat danh sach phan so =====\n";
    ds.output();

    cout << "\n===== 3. Tao n phan so ngau nhien =====\n";
    arrPhanSo ngauNhien;
    ngauNhien.taoNgauNhien(6);
    cout << "6 phan so ngau nhien: ";
    ngauNhien.output();

    cout << "\n===== 4. Tim phan so co gia tri lon nhat =====\n";
    cPhanSo psMax;
    if (ds.timMax(psMax)) {
        cout << "Phan so lon nhat: ";
        psMax.output();
        cout << "\n";
    } else {
        cout << "Danh sach rong\n";
    }

    cout << "\n===== 5. Dem phan so co tu la so nguyen to =====\n";
    cout << "Co " << ds.demTuNguyenTo() << " phan so co tu la so nguyen to\n";

    cout << "\n===== 6. Sap xep cac phan so tang dan =====\n";
    arrPhanSo truocSapXep(ds);   // giữ bản gốc bằng constructor sao chép
    ds.sapXepTang();
    cout << "Truoc khi sap xep: ";
    truocSapXep.output();
    cout << "Sau khi sap xep  : ";
    ds.output();

    return 0;
}
