#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void partition(int A[], int left, int right, int &i, int &j, int pivot) {
    i = left;
    j = right;

    while (i <= j) {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i <= j) {
            std::swap(A[i], A[j]);
            i++;
            j--;
        }
    }
}

void QuickSort(int A[], int left, int right) {
    if (left >= right) return;

    int pivot = A[(left + right) / 2];
    int i, j;

    partition(A, left, right, i, j, pivot);

    QuickSort(A, left, j);
    QuickSort(A, i, right);
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    if (n <= 1) {
        XuatMang(a, n);
        return 0;
    }

    QuickSort(a, 0, n - 1);
    XuatMang(a, n);

    return 0;
}
