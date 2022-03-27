#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int num[10];
int n, m;
// bool visited[10];


void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	
	int start = 0;
	if (k != 0)
		start = arr[k-1];

	for (int i = start; i < n; i++)
	{
		arr[k] = i; // 인덱스 번호를 부분수열로 저장. ex) (0,0), (0,1) (0,2), (0,3), (1,2), (1,3), (2,3), (3,3) 이 배열 arr 에 저장된다
		func(k + 1);
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