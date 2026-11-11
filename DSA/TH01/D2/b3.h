#include <iostream>
#include <vector>
using namespace std;

void insertionSortDesc(vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], k = i - 1;
        while (k >= 0 && a[k] < x) {    // giảm dần: dịch các phần tử NHỎ hơn x sang phải
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSortDesc(a, n);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}