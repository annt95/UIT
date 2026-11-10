#include <vector>
#include <string>
#include <iostream>

using namespace std;

void readInput(int &n, int &budget, vector<string> &name, vector<int> &price) {
    cin >> n;
    name.resize(n);
    price.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> price[i];
    }
    cin >> budget;
}

void findDeal(int n, int budget, vector<string> &name, vector<int> &price) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (price[i] < budget) {
            cout << name[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No items found" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, budget;
    vector<string> name;
    vector<int> price;
    readInput(n, budget, name, price);
    findDeal(n, budget, name, price);
    return 0;
}