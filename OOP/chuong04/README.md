# Bài tập cuối Chương 4 – Việc khởi tạo đối tượng, hàm bạn và lớp bạn

- **MSSV:** 26730083
- **Họ và tên:** Ngô Thành An
- **Môn:** Lập trình hướng đối tượng – C++17, chỉ dùng thư viện chuẩn

Mỗi bài là một file `.cpp` độc lập, có `main()` riêng. Đầu mỗi file có đúng 3 dòng comment MSSV / Họ và tên / Ngày sinh theo quy định của môn. Đề lấy từ slide Chương 4, trang 48–52.

## Danh sách file

| File | Bài | Lớp | Tóm tắt đề | Kiến thức Chương 4 được dùng |
| --- | --- | --- | --- | --- |
| [`26730083_NgoThanhAn_Bai1.cpp`](26730083_NgoThanhAn_Bai1.cpp) | 1 | `cArray` | Nhập n phần tử, xuất, tạo n số ngẫu nhiên, đếm x, kiểm tra tăng dần, tìm phần tử lẻ nhỏ nhất, sắp xếp tăng dần | Mảng `int*` cấp phát động; constructor sao chép + destructor + toán tử gán |
| [`26730083_NgoThanhAn_Bai2.cpp`](26730083_NgoThanhAn_Bai2.cpp) | 2 | `cPhanSo`, `arrPhanSo` | Nhập, xuất, tạo n phân số ngẫu nhiên, tìm phân số lớn nhất, đếm phân số có tử là số nguyên tố, sắp xếp tăng dần | Mảng đối tượng cấp phát động (`new cPhanSo[n]` gọi constructor mặc định); **lớp bạn** `friend class arrPhanSo` |
| [`26730083_NgoThanhAn_Bai3.cpp`](26730083_NgoThanhAn_Bai3.cpp) | 3 | `cDonThuc` | Đơn thức `a·x^b`: tạo lập (a, b), nhập / thay đổi (get, set), xuất, giá trị tại x, đạo hàm, tổng 2 đơn thức cùng bậc | **Hàm bạn** `friend cDonThuc tong(...)` |
| [`26730083_NgoThanhAn_Bai4.cpp`](26730083_NgoThanhAn_Bai4.cpp) | 4 | `cDaThuc` | Đa thức bậc n: khởi tạo bậc 0 / bậc n, giá trị tại x, nhập, xuất, cộng, trừ; main nhập 2 đa thức rồi tính tổng | Mảng hệ số `double*` cấp phát động; constructor sao chép + destructor + toán tử gán |
| [`26730083_NgoThanhAn_Bai5.cpp`](26730083_NgoThanhAn_Bai5.cpp) | 5 | `cBook`, `cListBook` | Sách: thiết lập, nhập, xuất, truy vấn và cập nhật; danh sách: nhập, xuất, sách xuất bản gần đây nhất | Mảng đối tượng `cBook` cấp phát động bên trong `cListBook` |

Về tên lớp: `arrPhanSo` giữ đúng tên trong đề; "lớp Đơn thức" đặt là `cDonThuc`; "lớp DaThuc" đặt là `cDaThuc` để thống nhất tiền tố `c`.

Thư mục `tailieu/` chỉ chứa slide Chương 4 để tham khảo, không thuộc bài nộp.

## Compile và chạy

Compile và chạy một bài:

```bash
g++ -std=c++17 -Wall -Wextra 26730083_NgoThanhAn_Bai1.cpp -o Bai1.out
./Bai1.out
```

Chạy với input có sẵn, không cần gõ tay:

```bash
printf '6\n5 -3 8 -7 2 9\n8\n' | ./Bai1.out
```

Compile cả 5 bài một lần (file `.out` đã được `.gitignore` bỏ qua):

```bash
for f in 26730083_NgoThanhAn_*.cpp; do g++ -std=c++17 -Wall -Wextra "$f" -o "${f%.cpp}.out" || echo "LOI: $f"; done
```

## Kết quả kiểm tra

- 5/5 file compile bằng `g++ -std=c++17 -Wall -Wextra`: **0 warning, 0 error** (Apple clang 21).
- Chạy thêm AddressSanitizer + UndefinedBehaviorSanitizer với input mẫu: không có lỗi bộ nhớ.
- Chạy với stdin rỗng: không bài nào bị treo.
- Các trường hợp biên đã thử:
  - Mảng: không có số lẻ; dãy đã tăng dần; số lẻ âm (-7) vẫn được nhận là số lẻ.
  - Phân số: `4/6` được lưu tối giản là `2/3`, nên tử là 2 (số nguyên tố).
  - Đơn thức: 2 đơn thức khác bậc thì không cộng; số mũ âm bị từ chối.
  - Đa thức: `(x^2 + 1) + (-x^2 + 3) = 4`, bậc tự giảm về 0.
  - Sách: 2 cuốn cùng năm xuất bản mới nhất thì in cả 2.

## Ví dụ input / output

> Khi chạy bằng `printf ... |`, giá trị nhập không hiện ra màn hình nên các câu `Nhap ...:` nằm liền nhau. Khi chạy tay thì gõ từng giá trị rồi Enter.

### Bài 1. cArray

Input: `n = 6`, các phần tử `5 -3 8 -7 2 9`, `x = 8`. Dãy ở mục 3 là số ngẫu nhiên nên mỗi lần chạy sẽ khác.

```bash
printf '6\n5 -3 8 -7 2 9\n8\n' | ./26730083_NgoThanhAn_Bai1.out
```

```text
===== 1. Nhap day so nguyen gom n phan tu =====
Nhap so phan tu n:   a[0] =   a[1] =   a[2] =   a[3] =   a[4] =   a[5] = 
===== 2. Xuat day so nguyen =====
5 -3 8 -7 2 9 

===== 3. Tao day gom n so nguyen ngau nhien =====
Day ngau nhien (n = 10): 17 19 57 57 -27 85 52 -14 4 76 

===== 4. Dem so lan xuat hien cua x =====
Nhap x: So 8 xuat hien 1 lan trong day vua nhap

===== 5. Kiem tra day tang dan =====
Day vua nhap KHONG tang dan

===== 6. Tim phan tu le nho nhat =====
Phan tu le nho nhat: -7

===== 7. Sap xep tang dan =====
Truoc khi sap xep: 5 -3 8 -7 2 9 
Sau khi sap xep  : -7 -3 2 5 8 9 
Kiem tra lai: day da tang dan
```

### Bài 2. arrPhanSo

Input: `n = 4`, các phân số `1/2`, `4/6`, `-3/5`, `7/3`. Mục 3 là phân số ngẫu nhiên.

```bash
printf '4\n1 2\n4 6\n-3 5\n7 3\n' | ./26730083_NgoThanhAn_Bai2.out
```

```text
===== 1. Nhap cac phan so =====
Nhap so phan so n: Phan so thu 1:
  Nhap tu so:   Nhap mau so: Phan so thu 2:
  Nhap tu so:   Nhap mau so: Phan so thu 3:
  Nhap tu so:   Nhap mau so: Phan so thu 4:
  Nhap tu so:   Nhap mau so: 
===== 2. Xuat danh sach phan so =====
1/2   2/3   -3/5   7/3   

===== 3. Tao n phan so ngau nhien =====
6 phan so ngau nhien: -1/7   -9/10   3/2   4/7   -1   -3/8   

===== 4. Tim phan so co gia tri lon nhat =====
Phan so lon nhat: 7/3

===== 5. Dem phan so co tu la so nguyen to =====
Co 2 phan so co tu la so nguyen to

===== 6. Sap xep cac phan so tang dan =====
Truoc khi sap xep: 1/2   2/3   -3/5   7/3   
Sau khi sap xep  : -3/5   1/2   2/3   7/3   
```

### Bài 3. cDonThuc

Input: d1 = `3x^2`, d2 = `5x^2`, `x = 2`.

```bash
printf '3 2\n5 2\n2\n' | ./26730083_NgoThanhAn_Bai3.out
```

```text
===== 1. Tao lap don thuc khi biet he so va so mu =====
cDonThuc(3, 2) = 3x^2

===== 2. Thay doi thong tin don thuc (get / set) =====
Sau setHeSo(-1), setSoMu(5): d = -x^5  (he so -1, so mu 5)
setSoMu(-2) bi tu choi vi so mu am

===== 3. Nhap 2 don thuc =====
Don thuc d1:
  Nhap he so a:   Nhap so mu b (>= 0): Don thuc d2:
  Nhap he so a:   Nhap so mu b (>= 0): 
===== 4. Xuat 2 don thuc =====
d1 = 3x^2
d2 = 5x^2

===== 5. Tinh gia tri don thuc khi biet x =====
Nhap x: d1(2) = 12
d2(2) = 20

===== 6. Dao ham cua don thuc =====
d1' = 6x
d2' = 10x

===== 7. Tong 2 don thuc cung bac (ham ban) =====
d1 + d2 = 8x^2
```

Nếu nhập d1 = `2x^3`, d2 = `4x` (khác bậc), mục 7 in `d1 va d2 khong cung bac nen khong cong thanh 1 don thuc duoc`.

### Bài 4. cDaThuc

Input: P(x) bậc 2 với hệ số `1, -3, 2`; Q(x) bậc 3 với hệ số `2, 0, 1, -5` (nhập từ bậc cao xuống); `x = 2`.

```bash
printf '2\n1\n-3\n2\n3\n2\n0\n1\n-5\n2\n' | ./26730083_NgoThanhAn_Bai4.out
```

```text
===== 1. Khoi tao da thuc bac 0 va bac n =====
cDaThuc()               : 0  (bac 0)
cDaThuc(3) + gan he so  : 2x^3 - x + 5  (bac 3)

===== 2. Nhap 2 da thuc =====
Da thuc P(x):
  Nhap bac n (>= 0):   He so cua x^2:   He so cua x^1:   He so cua x^0: Da thuc Q(x):
  Nhap bac n (>= 0):   He so cua x^3:   He so cua x^2:   He so cua x^1:   He so cua x^0: 
===== 3. Xuat 2 da thuc =====
P(x) = x^2 - 3x + 2
Q(x) = 2x^3 + x - 5

===== 4. Tinh gia tri da thuc khi biet x =====
Nhap x: P(2) = 0
Q(2) = 13

===== 5. Tong hai da thuc =====
P(x) + Q(x) = 2x^3 + x^2 - 2x - 3  (bac 3)

===== 6. Hieu hai da thuc =====
P(x) - Q(x) = -2x^3 + x^2 - 4x + 7  (bac 3)
```

Với P(x) = `x^2 + 1` và Q(x) = `-x^2 + 3`, tổng là `4  (bac 0)`: bậc tự giảm khi hệ số bậc cao nhất bằng 0.

### Bài 5. cBook và cListBook

Input: 3 cuốn sách, mỗi cuốn nhập lần lượt mã, tên (có khoảng trắng), năm xuất bản, số trang.

```bash
printf '3\nS01\nLap trinh C++\n2020\n350\nS02\nCau truc du lieu\n2023\n420\nS03\nMang may tinh\n2023\n300\n' | ./26730083_NgoThanhAn_Bai5.out
```

```text
===== 1. Thiet lap thong tin sach (constructor) =====
Ma: S000 | Ten: Sach mau | Nam XB: 2015 | So trang: 200

===== 2. Truy van va cap nhat thong tin sach (get / set) =====
Truy van: ten = Sach mau, nam XB = 2015
setSoTrang(-5) bi tu choi vi so trang phai > 0
Sau khi cap nhat: Ma: S000 | Ten: Sach mau (tai ban) | Nam XB: 2024 | So trang: 250

===== 3. Nhap danh sach sach (moi cuon goi cBook::input) =====
Nhap so luong sach: Sach thu 1:
  Nhap ma sach:   Nhap ten sach:   Nhap nam xuat ban:   Nhap tong so trang: Sach thu 2:
  Nhap ma sach:   Nhap ten sach:   Nhap nam xuat ban:   Nhap tong so trang: Sach thu 3:
  Nhap ma sach:   Nhap ten sach:   Nhap nam xuat ban:   Nhap tong so trang: 
===== 4. Xuat danh sach sach =====
1. Ma: S01 | Ten: Lap trinh C++ | Nam XB: 2020 | So trang: 350
2. Ma: S02 | Ten: Cau truc du lieu | Nam XB: 2023 | So trang: 420
3. Ma: S03 | Ten: Mang may tinh | Nam XB: 2023 | So trang: 300

===== 5. Sach duoc xuat ban gan day nhat =====
Nam xuat ban gan day nhat: 2023
Ma: S02 | Ten: Cau truc du lieu | Nam XB: 2023 | So trang: 420
Ma: S03 | Ten: Mang may tinh | Nam XB: 2023 | So trang: 300
```
