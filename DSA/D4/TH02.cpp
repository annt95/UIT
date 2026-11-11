#include <iostream>

using namespace std;
#define MAXN 150000

void ChenTang(int x, int a[], int &n)
{
    int k = n - 1;
    while (k >= 0 && a[k] > x)
    {
        a[k + 1] = a[k];
        k--;
    }
    a[k + 1] = x;
    n++;
}


void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}


void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

