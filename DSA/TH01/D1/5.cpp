#include <iostream>
#include <vector>
using namespace std;

void PrintArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
}

void InsertionSort(int a[], int n) {
    int k, x;
    cout << "Sap xep:\n";
    for (int i = 1; i < n; i++) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi xu ly: ";
        PrintArray(a, n);
        cout << "\n";

        k = i - 1;
        x = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << x << "\n";

        for (; k >= 0 && a[k] > x; k--);
        k++;
        cout << "Chen " << x << " vao vi tri k = " << k << "\n";

        for (int j = i; j > k; j--)
            a[j] = a[j - 1];
        a[k] = x;

        cout << "Mang sau khi xu ly: ";
        PrintArray(a, n);
        cout << "\n\n";
    }
}

int main() {
    int size;
    cin >> size;

    vector<int> A(size);
    for (int i = 0; i < size; i++)
        cin >> A[i];

    cout << "Mang truoc khi sap xep:\n";
    PrintArray(A.data(), size);
    cout << "\n\n";

    InsertionSort(A.data(), size);

    cout << "Mang sau khi sap xep:\n";
    PrintArray(A.data(), size);
    cout << "\n";

    return 0;
}