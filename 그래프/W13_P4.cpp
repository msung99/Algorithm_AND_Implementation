#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int size, n;
	cin >> size >> n;
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int data;
			cin >> data;
			arr[i][j] = data;
		}
	}

	for (int i = 0; i < n; i++) {
		int* arr2 = new int[size];
		int* arr3 = new int[size];
		int index2 = 0;
		int size2 = 0;
		int index3 = 0;
		int size3 = 0;
		int x, y;
		cin >> x >> y;

		if (y == 0)
			y = 1;

		else if (y == 1)
			y = 0;

		for (int j = 0; j < size; j++) {
			if (arr[x - 1][j] == 2) {
				arr2[index2] = j;
				index2++;
				size2++;
			}
		}

		for (int j = 0; j < size2; j++) {
			for (int k = 0; k < size; k++) {
				if (k != x - 1 && arr[arr2[j]][k] == y + 1 && arr[x - 1][k] == 0) {
					bool check = true;
					for (int t = 0; t < size3; t++) {
						if (arr3[t] == k + 1)
							check = false;
					}
					if (check) {
						arr3[index3] = k + 1;
						index3++;
						size3++;
					}
				}
			}
		}
		sort(arr3, arr3 + size3);
		if (size3 == 0)
			cout << 0 << endl;
		else {
			for (int i = 0; i < size3; i++) {
				cout << arr3[i] << ' ';
			}
		}
		cout << endl;
	}
}
