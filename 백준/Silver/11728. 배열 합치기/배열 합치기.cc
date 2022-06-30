#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
int arr1[1000001], arr2[1000001], result[1000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	int idx1 = 0, idx2 = 0;

	for (int i = 0; i < n + m; i++) {
		if (idx2 == m) {  // arr2 배열에서 비교할 원소를 다 써버린 경우
			result[i] = arr1[idx1];
			idx1++;
		}
		else if (idx1 == n) { // arr1 배열에서 비교할 원소를 다 써버린 경우
			result[i] = arr2[idx2];
			idx2++;
		}
		else if (arr1[idx1] <= arr2[idx2]) {
			result[i] = arr1[idx1];
			idx1++;
		}
		else {
			result[i] = arr2[idx2];
			idx2++;
		}
	}

	for (int i = 0; i < n + m; i++) {
		cout << result[i] << ' ';
	}

	/*
	for(int i=0; i<n+m; i++)
	{
		if (arr1.empty()) {
			cout << arr2.front() << ' ';
			break;
		}
		if (arr2.empty()) {
			cout << arr1.front() << ' ';
			break;
		}

		if (arr1.front() < arr2.front()) {
			cout << arr1.front() << ' ';
			arr1.erase(arr1.begin());
		}
		else if(arr1.front() >= arr2.front()){
			cout << arr2.front() << ' ';
			arr2.erase(arr2.begin());
		}
	}
	*/
}