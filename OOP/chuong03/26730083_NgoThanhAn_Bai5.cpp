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

    void capPhatVaChep(const int b[], int soPhanTu);   // cấp phát vùng nhớ mới rồi chép b vào

public:
    cArray();                                // mảng rỗng
    cArray(int soPhanTu);                    // n số nguyên ngẫu nhiên trong [-100, 100]
    cArray(const int b[], int soPhanTu);     // tạo từ mảng có sẵn (để minh họa trường hợp đặc biệt)
    cArray(const cArray& other);             // constructor sao chép (sao chép sâu)
    ~cArray();                               // destructor: giải phóng bộ nhớ
    cArray& operator=(const cArray& other);  // toán tử gán (sao chép sâu)

    void output() const;                 // xuất mảng
    bool timAmLonNhat(int& kq) const;    // tìm số âm lớn nhất; trả về false nếu không có số âm
    int demX(int x) const;               // đếm số lần xuất hiện của x
    bool isGiamDan() const;              // kiểm tra mảng có giảm dần không
    void sapXepTang();                   // sắp xếp tăng dần
};

// Cấp phát vùng nhớ MỚI cho soPhanTu phần tử rồi chép từng phần tử của b sang
void cArray::capPhatVaChep(const int b[], int soPhanTu) {
    if (soPhanTu <= 0) {
        a = nullptr;
        n = 0;
        return;
    }
    n = soPhanTu;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

// Mảng rỗng: chưa cấp phát vùng nhớ
cArray::cArray() {
    a = nullptr;
    n = 0;
}

// Tạo mảng n số nguyên ngẫu nhiên trong đoạn [-100, 100]
cArray::cArray(int soPhanTu) {
    if (soPhanTu <= 0) {        // n không hợp lệ -> mảng rỗng
        a = nullptr;
        n = 0;
        return;
    }
    n = soPhanTu;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 201 - 100;   // rand() % 201 cho 0..200, trừ 100 được -100..100
}

// Tạo mảng từ mảng b có sẵn
cArray::cArray(const int b[], int soPhanTu) {
    capPhatVaChep(b, soPhanTu);
}

// Constructor sao chép: cấp phát vùng nhớ riêng rồi chép dữ liệu (không dùng chung con trỏ)
cArray::cArray(const cArray& other) {
    capPhatVaChep(other.a, other.n);
}

// Destructor: trả lại vùng nhớ đã cấp phát bằng new[]
cArray::~cArray() {
    delete[] a;     // delete[] với nullptr vẫn an toàn
}

// Toán tử gán: giải phóng vùng nhớ cũ rồi sao chép sâu từ other
cArray& cArray::operator=(const cArray& other) {
    if (this != &other) {       // tránh tự gán (x = x) làm mất dữ liệu
        delete[] a;
        capPhatVaChep(other.a, other.n);
    }
    return *this;
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

// Số âm lớn nhất là số âm gần 0 nhất; kq chỉ có nghĩa khi hàm trả về true
bool cArray::timAmLonNhat(int& kq) const {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 && (!timThay || a[i] > kq)) {
            kq = a[i];
            timThay = true;
        }
    }
    return timThay;
}

// Đếm số phần tử bằng x
int cArray::demX(int x) const {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            dem++;
    return dem;
}

// Giảm dần: không có cặp liền kề nào tăng (a[i] < a[i+1]); cho phép 2 số bằng nhau đứng cạnh nhau
bool cArray::isGiamDan() const {
    for (int i = 0; i < n - 1; i++)
        if (a[i] < a[i + 1])
            return false;
    return true;
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

    cout << "===== 1. Tao mang n so nguyen ngau nhien bang constructor =====\n";
    int n = 0;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    while (n <= 0 && cin) {         // dừng nếu cin lỗi để không lặp vô hạn
        cout << "n phai > 0, nhap lai: ";
        cin >> n;
    }
    cArray arr(n);

    cout << "\n===== 2. Xuat mang =====\n";
    arr.output();

    cout << "\n===== 3. Tim so am lon nhat =====\n";
    int amMax = 0;
    if (arr.timAmLonNhat(amMax))
        cout << "So am lon nhat: " << amMax << "\n";
    else
        cout << "Mang khong co so am\n";

    cout << "\n===== 4. Dem so lan xuat hien cua x =====\n";
    int x = 0;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So " << x << " xuat hien " << arr.demX(x) << " lan\n";

    cout << "\n===== 5. Kiem tra mang giam dan =====\n";
    if (arr.isGiamDan())
        cout << "Mang giam dan\n";
    else
        cout << "Mang KHONG giam dan\n";

    cout << "\n===== 6. Sao chep mang (constructor sao chep va toan tu gan) =====\n";
    cArray banSao(arr);    // gọi constructor sao chép
    cArray banGan;
    banGan = arr;          // gọi toán tử gán
    cout << "Ban sao (constructor sao chep): "; banSao.output();
    cout << "Ban gan (toan tu gan)         : "; banGan.output();

    cout << "\n===== 7. Sap xep tang dan =====\n";
    arr.sapXepTang();
    cout << "Mang sau khi sap xep : "; arr.output();
    cout << "Ban sao van giu nguyen: "; banSao.output();   // chứng tỏ sao chép sâu

    cout << "\n===== 8. Truong hop dac biet: mang khong co so am, giam dan =====\n";
    int duLieu[] = {9, 7, 7, 3, 0};
    cArray dacBiet(duLieu, 5);
    cout << "Mang: "; dacBiet.output();
    if (dacBiet.timAmLonNhat(amMax))
        cout << "So am lon nhat: " << amMax << "\n";
    else
        cout << "Mang khong co so am\n";
    if (dacBiet.isGiamDan())
        cout << "Mang giam dan\n";
    else
        cout << "Mang KHONG giam dan\n";

    return 0;
}
