#include <iostream>
#include <vector>
using namespace std;

void insertSorted(vector<int> &a, int &n, int x) {
    a.resize(n + 1);
    int k = n - 1;
    while (k >= 0 && a[k] > x) {
        a[k + 1] = a[k];
        k--;
    }
    a[k + 1] = x;
    n++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertSorted(a, n, x);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}