#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool xuat[100001] = {};
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (value <= n) xuat[value] = true;
    }

    int mex = 0;
    while (mex <= n && xuat[mex]) mex++;
    cout << mex << '\n';

    return 0;
}