#include <iostream>
#include <vector>
#include <string>
using namespace std;

void readInput(int &n, vector<string> &names, vector<int> &prices, int &budget) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int price;
        cin >> name >> price;
        names.push_back(name);
        prices.push_back(price);
    }
    cin >> budget;
}

void findDeals(int n, const vector<string> &names, const vector<int> &prices, int budget) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (prices[i] < budget) {
            cout << names[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No items found\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, budget;
    vector<string> names;
    vector<int> prices;

    readInput(n, names, prices, budget);
    findDeals(n, names, prices, budget);
    return 0;
}
