#include <iostream>
#include <algorithm>
using namespace std;

int origin_list[10];
int new_list[10];
int n, m;


// 이전에 풀었던 N과 M(4) 문제에서 살짝만 변형시키면 된다.
// new_list 가 0 ~ N 사이의 숫자를 가지고 조합을 만들게 하고, 그 조합의 숫자들은 origin_list 의 인덱스 번호를 나타내주면 된디.

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << origin_list[new_list[i]] << ' '; // new_list 에 기록해둔 인덱스에 대응되는 수를 출력
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		new_list[k] = i;
		func(k + 1);
	}
}


int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> origin_list[i];

	sort(origin_list, origin_list + n);  // 오름차순 정렬

	func(0);
}