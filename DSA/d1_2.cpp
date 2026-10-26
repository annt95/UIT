#include <iostream>

#include <vector>
#include <string>
#include <cstdint>
#include <string_view>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<uint32_t> offsets(n + 1);
    string words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        offsets[i] = static_cast<uint32_t>(words.size());
        words += word;
    }
    offsets[n] = static_cast<uint32_t>(words.size());

    string q;
    cin >> q;

    int left = 0, right = n - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        string_view word(words.data() + offsets[mid], offsets[mid + 1] - offsets[mid]);

        if (word == q) {
            answer = mid + 1; 
            right = mid - 1;
        } 
        else if (word < q) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}