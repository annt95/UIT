# Bài tập Chương 3 – Lớp và đối tượng

- **MSSV:** 26730083
- **Họ và tên:** Ngô Thành An
- **Môn:** Lập trình hướng đối tượng – C++17, chỉ dùng thư viện chuẩn

Mỗi bài là một file `.cpp` độc lập, có `main()` riêng. Đầu mỗi file có đúng 3 dòng comment MSSV / Họ và tên / Ngày sinh theo quy định của môn.

## Danh sách file

| File | Bài | Lớp | Tóm tắt đề |
| --- | --- | --- | --- |
| [`26730083_NgoThanhAn_BaiPhanSo.cpp`](26730083_NgoThanhAn_BaiPhanSo.cpp) | A | `cPhanSo` | Khởi tạo mặc định (0/1), khi biết tử và mẫu, từ một số nguyên; nhập, xuất; tổng, hiệu, tích, thương (rút gọn, xử lý mẫu = 0, mẫu âm, chia cho phân số 0) |
| [`26730083_NgoThanhAn_BaiCandidate.cpp`](26730083_NgoThanhAn_BaiCandidate.cpp) | B | `cCandidate` | Thí sinh gồm mã số, họ tên, giới tính, năm sinh, ĐTB; constructor mặc định / đủ tham số / sao chép; nhập, xuất, tính tuổi; `operator>>` và `operator<<` |
| [`26730083_NgoThanhAn_Bai1.cpp`](26730083_NgoThanhAn_Bai1.cpp) | 1 | `cHocSinh` | Nhập họ tên, điểm toán, điểm văn → ĐTB, xếp loại (Giỏi ≥ 8, Khá ≥ 6.5, Trung bình ≥ 5, Yếu < 5) |
| [`26730083_NgoThanhAn_Bai2.cpp`](26730083_NgoThanhAn_Bai2.cpp) | 2 | `cDiem`, `cDuongTron` | Nhập tọa độ tâm và bán kính → diện tích, chu vi đường tròn |
| [`26730083_NgoThanhAn_Bai3.cpp`](26730083_NgoThanhAn_Bai3.cpp) | 3 | `cDiem` | Nhập 2 điểm trong mặt phẳng Oxy → khoảng cách bằng `khoangCach(const cDiem&)` |
| [`26730083_NgoThanhAn_Bai4.cpp`](26730083_NgoThanhAn_Bai4.cpp) | 4 | `cHocSinh` | Nhập 2 học sinh (mã, họ tên, giới tính, năm sinh, ĐTB) → ai có ĐTB cao hơn, ai nhỏ tuổi hơn (có xử lý bằng nhau) |
| [`26730083_NgoThanhAn_Bai5.cpp`](26730083_NgoThanhAn_Bai5.cpp) | 5 | `cArray` | Mảng động `int*` theo rule of three: n số ngẫu nhiên trong [-100, 100], xuất, số âm lớn nhất, đếm x, kiểm tra giảm dần, sắp xếp tăng dần |
| [`26730083_NgoThanhAn_Bai6.cpp`](26730083_NgoThanhAn_Bai6.cpp) | 6 | `cSoPhuc` | Tạo lập, get/set phần thực và phần ảo; cộng, trừ, nhân, chia (xử lý chia cho 0); nhập, xuất dạng `a + bi` / `a - bi` |

Thư mục `tailieu/` chỉ chứa đề (PDF) và header mẫu của thầy để tham khảo, không thuộc bài nộp.

## Compile và chạy

Compile và chạy một bài:

```bash
g++ -std=c++17 -Wall -Wextra 26730083_NgoThanhAn_BaiPhanSo.cpp -o BaiPhanSo.out
./BaiPhanSo.out
```

Chạy với input có sẵn, không cần gõ tay:

```bash
printf '1 2\n1 3\n' | ./BaiPhanSo.out
```

Compile cả 8 bài một lần (file `.out` đã được `.gitignore` bỏ qua):

```bash
for f in 26730083_NgoThanhAn_*.cpp; do g++ -std=c++17 -Wall -Wextra "$f" -o "${f%.cpp}.out" || echo "LOI: $f"; done
```

## Kết quả kiểm tra

- 8/8 file compile bằng `g++ -std=c++17 -Wall -Wextra`: **0 warning, 0 error** (Apple clang 21).
- Chạy thêm AddressSanitizer + UndefinedBehaviorSanitizer với input mẫu: không có lỗi bộ nhớ (quan trọng nhất là `cArray`).
- Chạy với stdin rỗng: không bài nào bị treo, vì các vòng "nhập lại" đều dừng khi `cin` lỗi.
- Các trường hợp biên đã thử:
  - Phân số: mẫu âm `3/-6 → -1/2`, mẫu = 0 (constructor tự gán 1, `input()` bắt nhập lại), chia cho phân số 0.
  - Đường tròn: bán kính âm thì bắt nhập lại.
  - Học sinh: 2 học sinh bằng ĐTB và bằng tuổi.
  - Mảng: n ≤ 0 thì bắt nhập lại; mảng không có số âm; mảng giảm dần.
  - Số phức: chia cho `0 + 0i`; kết quả `-0` được in thành `0`.

## Ví dụ input / output

> Khi chạy bằng `printf ... |`, giá trị nhập không hiện ra màn hình nên các câu `Nhap ...:` nằm liền nhau. Khi chạy tay thì gõ từng giá trị rồi Enter.

### A. cPhanSo

Input: tử và mẫu của a là `1 2`, phân số b là `1 3`.

```bash
printf '1 2\n1 3\n' | ./26730083_NgoThanhAn_BaiPhanSo.out
```

```text
===== 1. Cac cach khoi tao phan so =====
cPhanSo()      = 0
cPhanSo(3, -6) = -1/2
cPhanSo(7)     = 7
cPhanSo(2, 0)  : [Canh bao] Mau so bang 0 khong hop le -> tu dong gan mau = 1
cPhanSo(2, 0)  = 2

===== 2. Khoi tao phan so a tu tu, mau do nguoi dung nhap =====
Nhap tu so cua a: Nhap mau so cua a: a = 1/2

===== 3. Nhap phan so b tu ban phim =====
Nhap tu so: Nhap mau so: b = 1/3

===== 4. Tong a + b =====
a + b = 5/6

===== 5. Hieu, tich, thuong =====
a - b = 1/6
a * b = 1/6
a : b = 3/2

===== 6. Xu ly chia cho phan so 0 =====
[Loi] Khong the chia cho phan so 0 -> tra ve 0
a : 0 = 0
```

### B. cCandidate

Input: 2 thí sinh, mỗi thí sinh nhập lần lượt mã số, họ tên (có khoảng trắng), giới tính (1/0), năm sinh, ĐTB. Tuổi được tính theo năm hiện tại của máy (ví dụ này chạy năm 2026).

```bash
printf 'TS002\nTran Thi Binh\n0\n2006\n7.25\nTS003\nLe Van Cuong\n1\n2004\n9\n' | ./26730083_NgoThanhAn_BaiCandidate.out
```

```text
===== 1. Tao lap thi sinh mac dinh =====
Ma so:  | Ho ten:  | Gioi tinh: Nam | Nam sinh: 2000 | DTB: 0

===== 2. Tao lap thi sinh khi biet day du thong tin =====
Ma so: TS001 | Ho ten: Nguyen Van An | Gioi tinh: Nam | Nam sinh: 2005 | DTB: 8.5

===== 3. Tao lap thi sinh tu thi sinh da co (constructor sao chep) =====
Ma so: TS001 | Ho ten: Nguyen Van An | Gioi tinh: Nam | Nam sinh: 2005 | DTB: 8.5

===== 4. Nhap thong tin thi sinh tu ban phim (input) =====
Nhap ma so: Nhap ho ten: Nhap gioi tinh (1: Nam, 0: Nu): Nhap nam sinh: Nhap diem trung binh: 
===== 5. Xuat thong tin thi sinh ra man hinh (output) =====
Ma so: TS002 | Ho ten: Tran Thi Binh | Gioi tinh: Nu | Nam sinh: 2006 | DTB: 7.25

===== 6. Cho biet tuoi cua thi sinh =====
Tuoi cua thi sinh TS001: 21
Tuoi cua thi sinh vua nhap: 20

===== 7. Nhap / xuat bang operator>> va operator<< =====
Nhap ma so: Nhap ho ten: Nhap gioi tinh (1: Nam, 0: Nu): Nhap nam sinh: Nhap diem trung binh: Thi sinh vua nhap: Ma so: TS003 | Ho ten: Le Van Cuong | Gioi tinh: Nam | Nam sinh: 2004 | DTB: 9
```

### Bài 1. Điểm trung bình và xếp loại

Input: họ tên `Nguyen Van A`, điểm toán `8.5`, điểm văn `7`.

```bash
printf 'Nguyen Van A\n8.5\n7\n' | ./26730083_NgoThanhAn_Bai1.out
```

```text
===== 1. Nhap thong tin hoc sinh =====
Nhap ho ten: Nhap diem toan: Nhap diem van: 
===== 2. Tinh diem trung binh =====
Diem trung binh: 7.75

===== 3. Xep loai =====
Xep loai: Kha

===== 4. Xuat ket qua =====
Ho ten: Nguyen Van A | Toan: 8.50 | Van: 7.00 | DTB: 7.75 | Xep loai: Kha

===== 5. Minh hoa 4 muc xep loai (constructor co tham so) =====
Ho ten: Hoc sinh A | Toan: 9.00 | Van: 8.00 | DTB: 8.50 | Xep loai: Gioi
Ho ten: Hoc sinh B | Toan: 7.00 | Van: 6.00 | DTB: 6.50 | Xep loai: Kha
Ho ten: Hoc sinh C | Toan: 5.00 | Van: 5.00 | DTB: 5.00 | Xep loai: Trung binh
Ho ten: Hoc sinh D | Toan: 4.00 | Van: 5.50 | DTB: 4.75 | Xep loai: Yeu
```

### Bài 2. Đường tròn

Input: tâm `(1, 2)`, bán kính `3`.

```bash
printf '1 2\n3\n' | ./26730083_NgoThanhAn_Bai2.out
```

```text
===== 1. Khoi tao duong tron (mac dinh va co tham so) =====
Duong tron tam (0.00, 0.00), ban kinh 1.00
Duong tron tam (1.00, 1.00), ban kinh 2.50

===== 2. Nhap duong tron tu ban phim =====
Nhap toa do tam:
  Nhap hoanh do x:   Nhap tung do y: Nhap ban kinh: Vua nhap: Duong tron tam (1.00, 2.00), ban kinh 3.00

===== 3. Tinh dien tich =====
Dien tich S = PI * r^2 = 28.27

===== 4. Tinh chu vi =====
Chu vi C = 2 * PI * r = 18.85
```

### Bài 3. Khoảng cách 2 điểm

Input: A `(1, 2)`, B `(4, 6)`.

```bash
printf '1 2\n4 6\n' | ./26730083_NgoThanhAn_Bai3.out
```

```text
===== 1. Khoi tao diem (mac dinh va co tham so) =====
O = (0.00, 0.00), M = (3.00, 4.00)
Khoang cach OM = 5.00

===== 2. Nhap toa do 2 diem =====
Diem A:
  Nhap hoanh do x:   Nhap tung do y: Diem B:
  Nhap hoanh do x:   Nhap tung do y: A = (1.00, 2.00), B = (4.00, 6.00)

===== 3. Tinh khoang cach giua 2 diem =====
Khoang cach AB = 5.00
```

### Bài 4. So sánh 2 học sinh

Input: 2 học sinh, mỗi học sinh nhập lần lượt mã, họ tên, giới tính (1/0), năm sinh, ĐTB. Tuổi tính theo năm hiện tại (ví dụ chạy năm 2026).

```bash
printf 'HS01\nNguyen Van A\n1\n2008\n8.5\nHS02\nTran Thi B\n0\n2009\n7\n' | ./26730083_NgoThanhAn_Bai4.out
```

```text
===== 1. Hoc sinh mau (constructor co tham so) =====
Ma: HS00 | Ho ten: Hoc Sinh Mau | Gioi tinh: Nam | Nam sinh: 2010 | Tuoi: 16 | DTB: 9

===== 2. Nhap thong tin 2 hoc sinh =====
--- Hoc sinh 1 ---
Nhap ma hoc sinh: Nhap ho ten: Nhap gioi tinh (1: Nam, 0: Nu): Nhap nam sinh: Nhap diem trung binh: --- Hoc sinh 2 ---
Nhap ma hoc sinh: Nhap ho ten: Nhap gioi tinh (1: Nam, 0: Nu): Nhap nam sinh: Nhap diem trung binh: 
===== 3. Thong tin 2 hoc sinh vua nhap =====
Ma: HS01 | Ho ten: Nguyen Van A | Gioi tinh: Nam | Nam sinh: 2008 | Tuoi: 18 | DTB: 8.5
Ma: HS02 | Ho ten: Tran Thi B | Gioi tinh: Nu | Nam sinh: 2009 | Tuoi: 17 | DTB: 7

===== 4. Hoc sinh co diem trung binh cao hon =====
Nguyen Van A co DTB cao hon (8.5 > 7)

===== 5. Hoc sinh co tuoi nho hon =====
Tran Thi B nho tuoi hon (17 < 18 tuoi)
```

Nếu 2 học sinh cùng ĐTB 8 và cùng sinh năm 2008, chương trình in `Hai hoc sinh co DTB bang nhau (8)` và `Hai hoc sinh bang tuoi (18 tuoi)`.

### Bài 5. cArray

Input: `n = 10`, `x = 5`. Mảng là số ngẫu nhiên nên mỗi lần chạy sẽ khác.

```bash
printf '10\n5\n' | ./26730083_NgoThanhAn_Bai5.out
```

```text
===== 1. Tao mang n so nguyen ngau nhien bang constructor =====
Nhap so phan tu n: 
===== 2. Xuat mang =====
-52 31 -56 78 96 81 10 3 -44 18 

===== 3. Tim so am lon nhat =====
So am lon nhat: -44

===== 4. Dem so lan xuat hien cua x =====
Nhap x: So 5 xuat hien 0 lan

===== 5. Kiem tra mang giam dan =====
Mang KHONG giam dan

===== 6. Sao chep mang (constructor sao chep va toan tu gan) =====
Ban sao (constructor sao chep): -52 31 -56 78 96 81 10 3 -44 18 
Ban gan (toan tu gan)         : -52 31 -56 78 96 81 10 3 -44 18 

===== 7. Sap xep tang dan =====
Mang sau khi sap xep : -56 -52 -44 3 10 18 31 78 81 96 
Ban sao van giu nguyen: -52 31 -56 78 96 81 10 3 -44 18 

===== 8. Truong hop dac biet: mang khong co so am, giam dan =====
Mang: 9 7 7 3 0 
Mang khong co so am
Mang giam dan
```

### Bài 6. cSoPhuc

Input: z1 = `3 + 4i`, z2 = `1 - 2i`.

```bash
printf '3 4\n1 -2\n' | ./26730083_NgoThanhAn_Bai6.out
```

```text
===== 1. Tao lap so phuc khi biet phan thuc va phan ao =====
z = 3 + 4i

===== 2. Lay gia tri phan thuc, phan ao (get) =====
Phan thuc cua z: 3
Phan ao cua z  : 4

===== 3. Thay doi phan thuc, phan ao (set) =====
Sau setThuc(-2), setAo(-5): z = -2 - 5i

===== 4. Nhap 2 so phuc =====
So phuc z1:
  Nhap phan thuc:   Nhap phan ao: So phuc z2:
  Nhap phan thuc:   Nhap phan ao: z1 = 3 + 4i
z2 = 1 - 2i

===== 5. Cong, tru, nhan, chia 2 so phuc =====
z1 + z2 = 4 + 2i
z1 - z2 = 2 + 6i
z1 * z2 = 11 - 2i
z1 / z2 = -1 + 2i

===== 6. Xu ly chia cho so phuc 0 =====
[Loi] Khong the chia cho so phuc 0 -> tra ve 0 + 0i
z1 / 0 = 0 + 0i
```
