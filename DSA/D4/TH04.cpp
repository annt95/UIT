

#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};


bool dungTruoc(const SanPham& left, const SanPham& right) {
    if (left.gia != right.gia) return left.gia < right.gia;
    return left.ma < right.ma;
}

void mergeSort(SanPham* a, SanPham* temp, int left, int right) {
    if (left >= right) return;

    int middle = left + (right - left) / 2;
    mergeSort(a, temp, left, middle);
    mergeSort(a, temp, middle + 1, right);

    int i = left;
    int j = middle + 1;
    int k = left;
    while (i <= middle && j <= right) {
        if (dungTruoc(a[i], a[j])) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= middle) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (int index = left; index <= right; index++) a[index] = temp[index];
}

void mergeSort(SanPham* a, int left, int right) {
    SanPham* temp = new SanPham[right - left + 1];
    mergeSort(a, temp, left, right);
    delete[] temp;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}
