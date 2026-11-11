
#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
 void SapXepChen_Decending(int A[], int &N)
{
    for (int i = 1; i < N; i++) {
        int x = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}


void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    SapXepChen_Decending(a, n);

    XuatMang(a, n);

    return 0;
}
