#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

void readInput(int &n, string &pool, vector<uint32_t> &offsets, string &query) {
    cin >> n;
    offsets.resize(n + 1);
    pool.reserve((size_t)n * 30); 
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        offsets[i] = (uint32_t)pool.size();
        pool += word;
    }
    offsets[n] = (uint32_t)pool.size();
    cin >> query;
}

int binarySearch(const string &pool, const vector<uint32_t> &offsets, int n, const string &query) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string_view w(pool.data() + offsets[mid], offsets[mid + 1] - offsets[mid]);
        if (w == query) {
            return mid + 1;
        } else if (w > query) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string pool, query;
    vector<uint32_t> offsets;
    readInput(n, pool, offsets, query);
    cout << binarySearch(pool, offsets, n, query) << "\n";

    return 0;
}