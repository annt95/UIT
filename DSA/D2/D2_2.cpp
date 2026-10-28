#include <iostream>
#include <climits>
#include <vector>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge_2_Sorted_subArray(int A[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int A[], int left, int right) {
    if (left >= right) return;

    int middle = (left + right) / 2;
    MergeSort(A, left, middle);
    MergeSort(A, middle + 1, right);
    merge_2_Sorted_subArray(A, left, middle, right);
}

void SapXepTron(int A[], int N) {
    if (N <= 1) return;
    MergeSort(A, 0, N - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    SapXepTron(a, n);

    XuatMang(a, n);

    return 0;
}
