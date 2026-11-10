#include <iostream>
#include <utility>
#include <vector>

void PrintArray(const std::vector<long long>& a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << a[i];
    }
}

void SelectionSort(std::vector<long long>& a) {
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }

        std::cout << "i = " << i << "\n";
        std::cout << "Mang truoc khi swap: ";
        PrintArray(a);
        std::cout << "\n";
        std::cout << "Phan tu nho nhat trong doan [" << i + 1 << ", " << n - 1
                  << "]: " << a[minIndex] << "\n";

        const long long current = a[i];
        const long long smallest = a[minIndex];
        std::cout << "Swap " << current << " va " << smallest << "\n";
        if (minIndex != i) std::swap(a[i], a[minIndex]);

        std::cout << "Mang sau khi swap: ";
        PrintArray(a);
        std::cout << "\n\n";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (long long& value : a) std::cin >> value;

    std::cout << "Mang truoc khi sap xep:\n";
    PrintArray(a);
    std::cout << "\n\nSap xep:\n";
    SelectionSort(a);
    std::cout << "Mang sau khi sap xep:\n";
    PrintArray(a);
    std::cout << "\n";

    return 0;
}
