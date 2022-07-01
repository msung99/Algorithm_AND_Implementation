// 이 문제는 메모리 제한으로 인해 sort() 을 사용할시에 메모리 초과가 뜬다.
// 메모리 제한이 8MB 이기 떄문이다.
// int 는 4 바이트이므로, 문제 조건인 1천만 크기의 배열을 선언할 경우 40MB 를 차치하게 된다.

// 배열의 인덱스를 10000 까지만 두고, 각 인덱스에는 인덱스에 해당하는 숫자 '개수' 를 배열의 값으로 저장해서 해결하면 된다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int data;
	cin >> n;
	while (n--) {
		cin >> data;
		arr[data]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
			}
		}
	}
}