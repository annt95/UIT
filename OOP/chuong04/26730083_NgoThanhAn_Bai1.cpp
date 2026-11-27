// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std;

class cArray {
private:
    int* a;   // con trỏ tới vùng nhớ cấp phát động chứa các phần tử
    int n;    // số phần tử

    void capPhat(int soPhanTu);   // giải phóng vùng nhớ cũ, cấp phát vùng mới (các phần tử = 0)

public:
    cArray();                                // mảng rỗng
    cArray(const cArray& other);             // constructor sao chép (sao chép sâu)
    ~cArray();                               // destructor: giải phóng bộ nhớ
    cArray& operator=(const cArray& other);  // toán tử gán (sao chép sâu)

    void input();                       // 1. nhập dãy n phần tử
    void output() const;                // 2. xuất dãy
    void taoNgauNhien(int soPhanTu);    // 3. tạo dãy n số ngẫu nhiên trong [-100, 100]
    int demX(int x) const;              // 4. đếm số lần xuất hiện của x
    bool isTangDan() const;             // 5. kiểm tra dãy tăng dần
    bool timLeNhoNhat(int& kq) const;   // 6. tìm phần tử lẻ nhỏ nhất; false nếu không có số lẻ
    void sapXepTang();                  // 7. sắp xếp tăng dần
};

// Giải phóng vùng nhớ cũ rồi cấp phát vùng nhớ mới cho soPhanTu phần tử
void cArray::capPhat(int soPhanTu) {
    delete[] a;                 // delete[] với nullptr vẫn an toàn
    if (soPhanTu <= 0) {
        a = nullptr;
        n = 0;
    } else {
        n = soPhanTu;
        a = new int[n]();       // () để các phần tử ban đầu bằng 0
    }
}

// Mảng rỗng: chưa cấp phát vùng nhớ
cArray::cArray() : a(nullptr), n(0) {}

// Constructor sao chép: cấp phát vùng nhớ RIÊNG rồi chép từng phần tử (không dùng chung con trỏ)
cArray::cArray(const cArray& other) : a(nullptr), n(0) {
    capPhat(other.n);
    for (int i = 0; i < n; i++)
        a[i] = other.a[i];
}

// Destructor: trả lại vùng nhớ đã cấp phát bằng new[]
cArray::~cArray() {
    delete[] a;
}

// Toán tử gán: bỏ vùng nhớ cũ, cấp phát mới rồi chép dữ liệu từ other
cArray& cArray::operator=(const cArray& other) {
    if (this != &other) {       // tránh tự gán (x = x) làm mất dữ liệu
        capPhat(other.n);
        for (int i = 0; i < n; i++)
            a[i] = other.a[i];
    }
    return *this;
}

// Nhập n (phải > 0) rồi nhập từng phần tử
void cArray::input() {
    int soPhanTu = 0;
    cout << "Nhap so phan tu n: ";
    cin >> soPhanTu;
    while (soPhanTu <= 0 && cin) {      // dừng nếu cin lỗi để không lặp vô hạn
        cout << "n phai > 0, nhap lai: ";
        cin >> soPhanTu;
    }
    capPhat(soPhanTu);
    for (int i = 0; i < n; i++) {
        cout << "  a[" << i << "] = ";
        cin >> a[i];
    }
}

// Xuất các phần tử trên một dòng
void cArray::output() const {
    if (n == 0) {
        cout << "(mang rong)\n";
        return;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

// Tạo dãy n số ngẫu nhiên: rand() % 201 cho 0..200, trừ 100 được -100..100
void cArray::taoNgauNhien(int soPhanTu) {
    capPhat(soPhanTu);
    for (int i = 0; i < n; i++)
        a[i] = rand() % 201 - 100;
}

// Đếm số phần tử bằng x
int cArray::demX(int x) const {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            dem++;
    return dem;
}

// Tăng dần: không có cặp liền kề nào giảm (a[i] > a[i+1]); cho phép 2 số bằng nhau đứng cạnh nhau
bool cArray::isTangDan() const {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

// Số lẻ là số chia 2 dư khác 0 (đúng cả với số âm vì -3 % 2 = -1); kq chỉ có nghĩa khi trả về true
bool cArray::timLeNhoNhat(int& kq) const {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && (!timThay || a[i] < kq)) {
            kq = a[i];
            timThay = true;
        }
    }
    return timThay;
}

// Sắp xếp tăng dần bằng thuật toán đổi chỗ trực tiếp (Interchange Sort)
void cArray::sapXepTang() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i]) {
                int tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
}

int main() {
    srand((unsigned int)time(0));   // khởi tạo bộ sinh số ngẫu nhiên MỘT lần ở đầu chương trình

    cout << "===== 1. Nhap day so nguyen gom n phan tu =====\n";
    cArray arr;
    arr.input();

    cout << "\n===== 2. Xuat day so nguyen =====\n";
    arr.output();

    cout << "\n===== 3. Tao day gom n so nguyen ngau nhien =====\n";
    cArray ngauNhien;
    ngauNhien.taoNgauNhien(10);
    cout << "Day ngau nhien (n = 10): ";
    ngauNhien.output();

    cout << "\n===== 4. Dem so lan xuat hien cua x =====\n";
    int x = 0;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So " << x << " xuat hien " << arr.demX(x) << " lan trong day vua nhap\n";

    cout << "\n===== 5. Kiem tra day tang dan =====\n";
    if (arr.isTangDan())
        cout << "Day vua nhap tang dan\n";
    else
        cout << "Day vua nhap KHONG tang dan\n";

    cout << "\n===== 6. Tim phan tu le nho nhat =====\n";
    int leMin = 0;
    if (arr.timLeNhoNhat(leMin))
        cout << "Phan tu le nho nhat: " << leMin << "\n";
    else
        cout << "Day khong co phan tu le\n";

    cout << "\n===== 7. Sap xep tang dan =====\n";
    cArray truocSapXep(arr);    // giữ bản gốc bằng constructor sao chép
    arr.sapXepTang();
    cout << "Truoc khi sap xep: ";
    truocSapXep.output();
    cout << "Sau khi sap xep  : ";
    arr.output();
    if (arr.isTangDan())
        cout << "Kiem tra lai: day da tang dan\n";

    return 0;
}
