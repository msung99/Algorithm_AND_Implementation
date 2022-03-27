#include <iostream>
using namespace std;

int n, s;
int num_list[100];

int cnt;

void func(int cur, int total) // cur : 현재 탐색하며 살펴보고 있는 숫자의 인덱스 번호, total : 부분수열의 원소들의 합
{
	if (cur == n) // 부분수열의 원소가 n개가 되었을 때
	{
		if (total == s) // 만든 부분수열의 원소들의 합이 s 가 되었다면
			cnt++; // 경우의 수 카운팅
		return;
	}
	// 부분수열에 들어갈 주어진 숫자들에 대해 2가지 경우로 나눔. 1) 수열에 그 숫자( = num_list[cur])를 포함시킨다 2) 포함 안시킨다
	func(cur + 1, total); // 부분수열에 포함 안시키는 경우
	func(cur + 1, total + num_list[cur]); // 포함시키는 경우 
}

int main(void)
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num_list[i];

	func(0, 0);
	if (s == 0)  // 부분수열의 크기가 양수인것만 카운팅 한다고 했으므로 공집합은 제외해 줘야함. s가 0이 아닐때는 상관없고, s 가 0일때는 cnt에서 1을 뺴줘야함
		cnt--;
	cout << cnt;
}
