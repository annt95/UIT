//
// Created by Uyên on 28/10/26.
//

#include "D2_Demo.h"

int main() {
    HocSinh hs;
    hs.setMaTS("HS01");
    hs.setHoTen("Nguyen Van A");
    hs.setDiemMon("Toan", 8);
    hs.setDiemMon("Ly", 7);
    hs.setDiemMon("Hoa", 9);

    KhoiNganhA a;
    KhoiNganhB b;
    KhoiNganhC c;

    if (a.dangKy(hs))
        cout << "HS du dieu kien khoi A\n";
    else
        cout << "HS khong du dieu kien khoi A\n";

    if (b.dangKy(hs))
        cout << "HS du dieu kien khoi B\n";
    else
        cout << "HS khong du dieu kien khoi B\n";

    if (c.dangKy(hs))
        cout << "HS du dieu kien khoi C\n";
    else
        cout << "HS khong du dieu kien khoi C\n";

    return 0;
}
