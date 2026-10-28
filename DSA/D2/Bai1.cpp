#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge_2_Sorted_subArray(int A[], int left, int middle, int right) {
    if (left >= right) return;

    std::vector<int> temp;
    int i = left;
    int j = middle + 1;

    while (i <= middle && j <= right) {
        if (A[i] <= A[j])
            temp.push_back(A[i++]);
        else
            temp.push_back(A[j++]);
    }

    while (i <= middle)
        temp.push_back(A[i++]);
    while (j <= right)
        temp.push_back(A[j++]);

    for (int k = 0; k < temp.size(); ++k)
        A[left + k] = temp[k];
}

void MergeSort(int A[], int left, int right) {
    if (left >= right) return;

    int middle = (left + right) / 2;
    MergeSort(A, left, middle);
    MergeSort(A, middle + 1, right);
    merge_2_Sorted_subArray(A, left, middle, right);
}

void XuatMang(int A[], const int &N) {
    if (N == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    if (n == 0) {
        XuatMang(a, n);
        return 0;
    }

    MergeSort(a, 0, n - 1);
    XuatMang(a, n);

    return 0;
}
