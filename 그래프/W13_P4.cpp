#include <iostream>
using namespace std;

int main() {
	int size, n;

	cin >> size >> n;

	int** arr = new int* [size] {};

	for (int i = 0; i < size; i++) {
		arr[i] = new int[size] {};
	}

	int x, y;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> x;
			arr[i][j] = x;
		}
	}


	for (int i = 0; i < n; i++) {
		int index2 = 0;
		int index3 = 0;
		int size2 = 0;
		int size3 = 0;
		cin >> x >> y;
		/*y를 재설정. 0을 입력받으면 y+1 = 2 가되게만들어서 동료의 동료를 찿게 만들고, 1을 입력받으면 y+1 = 1 이 되게 만들어서 동료의 친구를 찾게 만든다.*/
		if (y == 0)
		{
			y = 1;
		}
		else if (y == 1)
		{
			y = 0;
		}

		int* arr2 = new int[size] {}; // 동료를 저장하는 배열
		int* arr3 = new int[size] {};  // 동료의 동료를 저장하는 배열
		for (int j = 0; j < size; j++) {
			if (arr[x - 1][j] == 2) {  // 동료 저장 
				arr2[index2] = j;
				size2++;
				index2++;
			}
		}
		// 1을 찾은경우 해당 열 좌표를 저장해 놓은 배열 arr2 에 대해서 또 탐색을 진행해서, 이 안에서 1을 찾고 또 열 좌표를 arr3 배열에 담아낸다.
		// 조건1 : 동료의 행(arr2) 에서 자기 자신(x-1)을 찾으면 배제해주는 것
		// 조건2 : 직계동료(arr2[j])의 동료(arr[j][k])를 찾아냄
		// 조건 3 : 조건2를 통해 찾아낸 동료의 동료가 자신의 동료이거나 친구인 사람들을 배제해주는 것 ( 0은 아무런 관계가 없다는 것이기 문. 1인 경우는 친구인 것이고, 2인 경우는 동료인 경우이다.)
			for (int j = 0; j < size2; j++) {
				for (int k = 0; k < size; k++) {
					if (k != x - 1 && arr[arr2[j]][k] == y + 1 && arr[x - 1][k] == 0) {
						bool flag = true; // arr3 배열에 동일한 동료의 동료를 중복해서 또 삽입하는 상황을 방지하기 위함 
						for (int t = 0; t < size3; t++) {
							if (arr3[t] == k + 1)  // 찾아낸 동료의 동료가 이미 arr3 배열에 저장되있는 경우
								flag = false;
					}
					// arr3 배열을 다 탐색해봤는데, 찾아낸 동료의 동료가 arr3 에 없어서 삽입해도 괜찮은 경우라면 삽입한다.
					if (flag) {
						arr3[index3] = k + 1;
						size3++;
						index3++;
					}

				}
			}
		}
		// arr3 에는 최종적으로 친구의 친구인 녀석의 번호가 쌓인다. 이때 오름차순 출력을 위해 sorting 과정을 진행한다.
		for (int j = 0; j < size3 - 1; j++) {
			for (int k = j + 1; k < size3; k++) {
				if (arr3[j] > arr3[k]) {
					int temp = arr3[j];
					arr3[j] = arr3[k];
					arr3[k] = temp;
				}
			}
		}
		if (size3 == 0)
			cout << 0 << endl;
		else {
			for (int j = 0; j < size3; j++) {
				cout << arr3[j] << " ";
			}
			cout << endl;
		}
	}


}
