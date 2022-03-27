#include <iostream>
#include <algorithm>
using namespace std;

int arr[10]; // arr : 출력할 부분수열 원소들을 모아두는 배열
int num[10]; // num : 입력받은 원소들을 저장하고 있는 기존 배열
int n, m;
// bool visited[10];

void func(int k, int start)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	int tmp = 0;
	for (int i = start; i < n; i++)
	{
		if (tmp != num[i]) // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
		{
			arr[k] = num[i];
			tmp = arr[k];
			func(k + 1, i+1);
		}
	}
}


int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);  // 오름차순 정렬

	func(0, 0);
}