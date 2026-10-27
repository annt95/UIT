#include <iostream>

using namespace std;

const int MAXN = 100000;

void NhapMang(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void selection_ascending(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

bool is_ascending(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int a[MAXN], n;

	std::cin >> n;

	NhapMang(a, n);

	selection_ascending(a, n);

	std::cout << std::boolalpha << is_ascending(a, n);

	return 0;
}
