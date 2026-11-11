#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string name;
    char status;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> status;
        if (status == 'A') {
            cout << name << "\n";
            return 0;
        }
    }
    cout << "All Present\n";
    return 0;
}