#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<long long>& values) {
	for (long long value : values) {
		cout << value << ' ';
	}
	cout << '\n';
}

int main() {
	int size;
	cin >> size;

	vector<long long> values(size);
	for (long long& value : values) {
		cin >> value;
	}

	cout << "Mang truoc khi sap xep:\n";
	printArray(values);
	cout << "Sap xep:\n";

	for (int index = 1; index < size; ++index) {
		cout << "i = " << index << '\n';
		cout << "Mang truoc khi xu ly: ";
		printArray(values);

		long long current = values[index];
		cout << "Phan tu dang xet A[" << index << "] = " << current << '\n';

		int position = index;
		while (position > 0 && values[position - 1] > current) {
			values[position] = values[position - 1];
			--position;
		}
		values[position] = current;

		cout << "Chen " << current << " vao vi tri k = " << position << '\n';
		cout << "Mang sau khi xu ly: ";
		printArray(values);
	}

	cout << "Mang sau khi sap xep:\n";
	printArray(values);
	return 0;
}
