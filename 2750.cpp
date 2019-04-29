#include <iostream>
using namespace std;

int arr[1000];
int main() {
	int n, tmp, data;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data;
		arr[i] = data;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (arr[j] > arr[i]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}