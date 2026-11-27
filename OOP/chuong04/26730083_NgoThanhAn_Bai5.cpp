// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <string>
using namespace std;

class cBook {
private:
    string maSach;
    string tenSach;
    int namXB;      // năm xuất bản
    int soTrang;    // tổng số trang

public:
    cBook();                                                          // mặc định (cần để tạo mảng cBook)
    cBook(const string& ma, const string& ten, int nam, int trang);   // thiết lập khi biết đủ thông tin

    void input();            // nhập thông tin sách từ bàn phím
    void output() const;     // xuất thông tin sách ra màn hình

    // Truy vấn
    string getMaSach() const;
    string getTenSach() const;
    int getNamXB() const;
    int getSoTrang() const;

    // Cập nhật (trả về false nếu giá trị không hợp lệ)
    void setMaSach(const string& ma);
    void setTenSach(const string& ten);
    bool setNamXB(int nam);
    bool setSoTrang(int trang);
};

class cListBook {
private:
    cBook* ds;   // mảng động các đối tượng cBook
    int n;       // số sách

    void capPhat(int soSach);   // giải phóng mảng cũ, cấp phát mảng mới

public:
    cListBook();                                   // danh sách rỗng
    cListBook(const cListBook& other);             // constructor sao chép (sao chép sâu)
    ~cListBook();                                  // destructor: giải phóng bộ nhớ
    cListBook& operator=(const cListBook& other);  // toán tử gán (sao chép sâu)

    void input();                    // nhập danh sách sách
    void output() const;             // xuất danh sách sách
    void xuatSachMoiNhat() const;    // sách xuất bản gần đây nhất (có thể nhiều cuốn cùng năm)
};

// ===== Cài đặt cBook =====

cBook::cBook() : maSach(""), tenSach(""), namXB(2000), soTrang(0) {}

cBook::cBook(const string& ma, const string& ten, int nam, int trang)
    : maSach(ma), tenSach(ten), namXB(nam), soTrang(trang) {}

// Nhập thông tin; tên sách dùng getline để nhận cả khoảng trắng
void cBook::input() {
    cout << "  Nhap ma sach: ";
    cin >> maSach;
    cin.ignore(1000, '\n');     // bỏ ký tự xuống dòng còn sót lại trước khi getline
    cout << "  Nhap ten sach: ";
    getline(cin, tenSach);
    cout << "  Nhap nam xuat ban: ";
    cin >> namXB;
    cout << "  Nhap tong so trang: ";
    cin >> soTrang;
}

// Xuất thông tin sách trên một dòng
void cBook::output() const {
    cout << "Ma: " << maSach
         << " | Ten: " << tenSach
         << " | Nam XB: " << namXB
         << " | So trang: " << soTrang << "\n";
}

string cBook::getMaSach() const {
    return maSach;
}

string cBook::getTenSach() const {
    return tenSach;
}

int cBook::getNamXB() const {
    return namXB;
}

int cBook::getSoTrang() const {
    return soTrang;
}

void cBook::setMaSach(const string& ma) {
    maSach = ma;
}

void cBook::setTenSach(const string& ten) {
    tenSach = ten;
}

// Năm xuất bản phải > 0
bool cBook::setNamXB(int nam) {
    if (nam <= 0)
        return false;
    namXB = nam;
    return true;
}

// Số trang phải > 0
bool cBook::setSoTrang(int trang) {
    if (trang <= 0)
        return false;
    soTrang = trang;
    return true;
}

// ===== Cài đặt cListBook =====

// Giải phóng mảng cũ rồi cấp phát mảng mới gồm soSach cuốn sách
void cListBook::capPhat(int soSach) {
    delete[] ds;                // delete[] với nullptr vẫn an toàn
    if (soSach <= 0) {
        ds = nullptr;
        n = 0;
    } else {
        n = soSach;
        ds = new cBook[n];      // new[] gọi constructor mặc định cho từng cuốn sách
    }
}

cListBook::cListBook() : ds(nullptr), n(0) {}

// Constructor sao chép: cấp phát mảng RIÊNG rồi chép từng cuốn sách
cListBook::cListBook(const cListBook& other) : ds(nullptr), n(0) {
    capPhat(other.n);
    for (int i = 0; i < n; i++)
        ds[i] = other.ds[i];
}

cListBook::~cListBook() {
    delete[] ds;
}

// Toán tử gán: bỏ mảng cũ, cấp phát mảng mới rồi chép từ other
cListBook& cListBook::operator=(const cListBook& other) {
    if (this != &other) {       // tránh tự gán
        capPhat(other.n);
        for (int i = 0; i < n; i++)
            ds[i] = other.ds[i];
    }
    return *this;
}

// Nhập số sách (phải > 0) rồi nhập từng cuốn (gọi cBook::input)
void cListBook::input() {
    int soSach = 0;
    cout << "Nhap so luong sach: ";
    cin >> soSach;
    while (soSach <= 0 && cin) {    // dừng nếu cin lỗi để không lặp vô hạn
        cout << "So luong phai > 0, nhap lai: ";
        cin >> soSach;
    }
    capPhat(soSach);
    for (int i = 0; i < n; i++) {
        cout << "Sach thu " << i + 1 << ":\n";
        ds[i].input();
    }
}

// Xuất danh sách có đánh số thứ tự
void cListBook::output() const {
    if (n == 0) {
        cout << "(danh sach rong)\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        ds[i].output();
    }
}

// Tìm năm xuất bản lớn nhất rồi in tất cả sách có năm đó
void cListBook::xuatSachMoiNhat() const {
    if (n == 0) {
        cout << "Danh sach rong\n";
        return;
    }
    int namMoiNhat = ds[0].getNamXB();
    for (int i = 1; i < n; i++)
        if (ds[i].getNamXB() > namMoiNhat)
            namMoiNhat = ds[i].getNamXB();
    cout << "Nam xuat ban gan day nhat: " << namMoiNhat << "\n";
    for (int i = 0; i < n; i++)
        if (ds[i].getNamXB() == namMoiNhat)
            ds[i].output();
}

int main() {
    cout << "===== 1. Thiet lap thong tin sach (constructor) =====\n";
    cBook mau("S000", "Sach mau", 2015, 200);
    mau.output();

    cout << "\n===== 2. Truy van va cap nhat thong tin sach (get / set) =====\n";
    cout << "Truy van: ten = " << mau.getTenSach() << ", nam XB = " << mau.getNamXB() << "\n";
    mau.setTenSach("Sach mau (tai ban)");
    mau.setNamXB(2024);
    mau.setSoTrang(250);
    if (!mau.setSoTrang(-5))
        cout << "setSoTrang(-5) bi tu choi vi so trang phai > 0\n";
    cout << "Sau khi cap nhat: ";
    mau.output();

    cout << "\n===== 3. Nhap danh sach sach (moi cuon goi cBook::input) =====\n";
    cListBook ds;
    ds.input();

    cout << "\n===== 4. Xuat danh sach sach =====\n";
    ds.output();

    cout << "\n===== 5. Sach duoc xuat ban gan day nhat =====\n";
    ds.xuatSachMoiNhat();

    return 0;
}
