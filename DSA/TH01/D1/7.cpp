#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            answer = mid;       
            right = mid - 1;
        } else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return answer;
}

int main() {

    int x, n, number;
    cin >> x;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int result = binarySearch(a, n, x);
    cout << result << endl;
    return 0;
}