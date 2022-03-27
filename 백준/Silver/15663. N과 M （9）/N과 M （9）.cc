#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int num[10];
int n, m;
bool visited[10];


void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	int tmp = 0; // 중복 순열인지 확인하기 위해 필요한 임시변수
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && tmp != num[i]) // 이전 수열의 마지막 항(tmp)과 새로운 수열의 마지막 항(num[i])이 같으면 중복수열
		{
			arr[k] = num[i];
			visited[i] = true;
			tmp = arr[k];  // 수열의 마지막 항을 tmp 에 저장
			func(k + 1);
			visited[i] = false;
		}
	}
}


int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);  // 오름차순 정렬

	func(0);
}