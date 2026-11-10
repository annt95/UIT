
#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void quickSort(int A[], int left, int right) {
    while (left < right) {
        int i = left;
        int j = right;
        int pivot = A[left + (right - left) / 2];

        while (i <= j) {
            while (A[i] < pivot) i++;
            while (A[j] > pivot) j--;

            if (i <= j) {
                hoanvi(A[i], A[j]);
                i++;
                j--;
            }
        }

        if (j - left < right - i) {
            if (left < j) quickSort(A, left, j);
            left = i;
        } else {
            if (i < right) quickSort(A, i, right);
            right = j;
        }
    }
}

void SapXepNhanh_ascending(int A[], int N) {
    if (N > 1) quickSort(A, 0, N - 1);
}








int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    SapXepNhanh_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
