#include <iostream>

#include <string>

#include <vector>

using namespace std;


void Input(vector<string>& a, int n) {

string word;

a.reserve(n);

for (int i = 0; i < n; ++i) {

cin >> word;

a.push_back(word);

}

}


int BinarySearch(const vector<string>& a, const string& x) {

int first = 0;

int last = static_cast<int>(a.size()) - 1;


while (first <= last) {

int mid = first + (last - first) / 2;

if (a[mid] == x) {

return mid + 1;

}

if (a[mid] > x) {

last = mid - 1;

} else {

first = mid + 1;

}

}

return -1;

}


int main() {

ios::sync_with_stdio(false);

cin.tie(nullptr);


int n;

cin >> n;

vector<string> words;

Input(words, n);


string query;

cin >> query;

cout << BinarySearch(words, query) << '\n';

return 0;

}

