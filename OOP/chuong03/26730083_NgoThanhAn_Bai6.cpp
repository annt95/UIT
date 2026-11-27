// MSSV: 26730083
// Họ và tên: Ngô Thành An
// Ngày sinh: 31/01/1995

#include <iostream>
using namespace std;

class cSoPhuc {
private:
    double thuc;   // phần thực
    double ao;     // phần ảo

public:
    cSoPhuc();                                 // mặc định: 0 + 0i
    cSoPhuc(double phanThuc, double phanAo);   // tạo lập khi biết phần thực, phần ảo

    double getThuc() const;          // lấy phần thực
    double getAo() const;            // lấy phần ảo
    void setThuc(double phanThuc);   // thay đổi phần thực
    void setAo(double phanAo);       // thay đổi phần ảo

    void input();            // nhập số phức
    void output() const;     // xuất dạng a + bi hoặc a - bi
    bool isZero() const;     // kiểm tra có phải 0 + 0i không

    cSoPhuc cong(const cSoPhuc& z) const;   // this + z
    cSoPhuc tru(const cSoPhuc& z) const;    // this - z
    cSoPhuc nhan(const cSoPhuc& z) const;   // this * z
    cSoPhuc chia(const cSoPhuc& z) const;   // this / z
};

cSoPhuc::cSoPhuc() : thuc(0), ao(0) {}

cSoPhuc::cSoPhuc(double phanThuc, double phanAo) : thuc(phanThuc), ao(phanAo) {}

double cSoPhuc::getThuc() const {
    return thuc;
}

double cSoPhuc::getAo() const {
    return ao;
}

void cSoPhuc::setThuc(double phanThuc) {
    thuc = phanThuc;
}

void cSoPhuc::setAo(double phanAo) {
    ao = phanAo;
}

// Nhập phần thực và phần ảo
void cSoPhuc::input() {
    cout << "  Nhap phan thuc: ";
    cin >> thuc;
    cout << "  Nhap phan ao: ";
    cin >> ao;
}

// Xuất dạng a + bi (phần ảo >= 0) hoặc a - bi (phần ảo < 0)
void cSoPhuc::output() const {
    double t = thuc, a = ao;
    if (t == 0) t = 0;   // đổi -0 thành 0 để không in ra "-0"
    if (a == 0) a = 0;
    if (a >= 0)
        cout << t << " + " << a << "i";
    else
        cout << t << " - " << -a << "i";
}

// Số phức bằng 0 khi cả phần thực và phần ảo đều bằng 0
bool cSoPhuc::isZero() const {
    return thuc == 0 && ao == 0;
}

// (a + bi) + (c + di) = (a + c) + (b + d)i
cSoPhuc cSoPhuc::cong(const cSoPhuc& z) const {
    return cSoPhuc(thuc + z.thuc, ao + z.ao);
}

// (a + bi) - (c + di) = (a - c) + (b - d)i
cSoPhuc cSoPhuc::tru(const cSoPhuc& z) const {
    return cSoPhuc(thuc - z.thuc, ao - z.ao);
}

// (a + bi)(c + di) = (ac - bd) + (ad + bc)i
cSoPhuc cSoPhuc::nhan(const cSoPhuc& z) const {
    return cSoPhuc(thuc * z.thuc - ao * z.ao, thuc * z.ao + ao * z.thuc);
}

// (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2); không chia được cho 0 + 0i
cSoPhuc cSoPhuc::chia(const cSoPhuc& z) const {
    if (z.isZero()) {
        cout << "[Loi] Khong the chia cho so phuc 0 -> tra ve 0 + 0i\n";
        return cSoPhuc();
    }
    double mau = z.thuc * z.thuc + z.ao * z.ao;
    return cSoPhuc((thuc * z.thuc + ao * z.ao) / mau, (ao * z.thuc - thuc * z.ao) / mau);
}

int main() {
    cout << "===== 1. Tao lap so phuc khi biet phan thuc va phan ao =====\n";
    cSoPhuc z(3, 4);
    cout << "z = "; z.output(); cout << "\n";

    cout << "\n===== 2. Lay gia tri phan thuc, phan ao (get) =====\n";
    cout << "Phan thuc cua z: " << z.getThuc() << "\n";
    cout << "Phan ao cua z  : " << z.getAo() << "\n";

    cout << "\n===== 3. Thay doi phan thuc, phan ao (set) =====\n";
    z.setThuc(-2);
    z.setAo(-5);
    cout << "Sau setThuc(-2), setAo(-5): z = "; z.output(); cout << "\n";

    cout << "\n===== 4. Nhap 2 so phuc =====\n";
    cSoPhuc z1, z2;
    cout << "So phuc z1:\n";
    z1.input();
    cout << "So phuc z2:\n";
    z2.input();
    cout << "z1 = "; z1.output(); cout << "\n";
    cout << "z2 = "; z2.output(); cout << "\n";

    cout << "\n===== 5. Cong, tru, nhan, chia 2 so phuc =====\n";
    cout << "z1 + z2 = "; z1.cong(z2).output(); cout << "\n";
    cout << "z1 - z2 = "; z1.tru(z2).output(); cout << "\n";
    cout << "z1 * z2 = "; z1.nhan(z2).output(); cout << "\n";
    if (z2.isZero()) {
        cout << "z1 / z2 -> khong chia duoc vi z2 = 0\n";
    } else {
        cout << "z1 / z2 = "; z1.chia(z2).output(); cout << "\n";
    }

    cout << "\n===== 6. Xu ly chia cho so phuc 0 =====\n";
    cSoPhuc khong;               // 0 + 0i
    cSoPhuc kq = z1.chia(khong);
    cout << "z1 / 0 = "; kq.output(); cout << "\n";

    return 0;
}
