<div align="center">

# UIT Coursework

**Trường Đại học Công nghệ Thông tin**

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.16%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)
[![UIT](https://img.shields.io/badge/UIT-Coursework-E87500?style=for-the-badge)](https://www.uit.edu.vn/)

*Kho lưu trữ các bài thực hành C++ trong quá trình học tại UIT.*

</div>

---

## Bắt đầu

### Yêu cầu

- CMake 3.16 trở lên
- Trình biên dịch hỗ trợ C++17: MSVC, MinGW, GCC hoặc Clang

### Build toàn bộ project

Mở terminal tại thư mục project:

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

Với Linux hoặc macOS, có thể bỏ `--config Debug`:

```bash
cmake -S . -B build
cmake --build build
```

### Build và chạy một bài

Ví dụ build bài 3:

```powershell
cmake --build build --config Debug --target oop_bai3
```

Chạy trên Windows với Visual Studio generator:

```powershell
.\build\Debug\oop_bai3.exe
```

Trên Linux hoặc macOS:

```bash
./build/oop_bai3
```

Thay `oop_bai3` bằng target cần chạy:

| Bài | CMake target |
| --- | --- |
| DSA D1 - Bài 2 | `d1_2` |
| OOP D1 - Demo | `D1_demo` |
| OOP D1 - Bài 1 đến 8 | `oop_bai1` đến `oop_bai8` |
| OOP D1 - Kiểm tra 15 phút | `KT15p` |

## Cấu hình C++

Các target được khai báo trong [`CMakeLists.txt`](CMakeLists.txt). Project yêu cầu chuẩn **C++17**.

## Ghi chú

- Mỗi file bài tập có hàm `main()` riêng, vì vậy hãy build và chạy từng target tương ứng.
- Thư mục `build/` chứa file sinh ra khi biên dịch và đã được Git bỏ qua.
