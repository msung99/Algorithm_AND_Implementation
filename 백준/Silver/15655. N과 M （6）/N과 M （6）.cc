#include <iostream>
#include <algorithm>
using namespace std;

int origin_list[10];
int new_list[10];
bool visited[10];
int n, m;


// 이전에 풀었던 N과 M(2) - 조합 구하기 문제에서 살짝만 변형시키면 된다.
// new_list 가 0 ~ N 사이의 숫자를 가지고 조합을 만들게 하고, 그 조합의 숫자들은 origin_list 의 인덱스 번호를 나타내주면 된디.

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << origin_list[new_list[i]] << ' '; // new_list 에 기록해둔 인덱스에 대응되는 수를 출력
		cout << '\n';
	}

	int start = 0;
	if (k != 0)
		start = new_list[k - 1] + 1;

	// num_list 는 0~N 사이의 숫자로 구성된 조합 부분순열이 저장됨. 
	// 예를들어 (0,1), (0,2), (0,3), (1,2), (1,3), (2,3) 이런 6개의 부분수열에 num_list이 저장된다.
	// num_list 의 원소들은 new_list 의 인덱스 번호로 활용된다. 
	for (int i = start; i < n; i++)
	{
		if (!visited[i])
		{
			new_list[k] = i;
			visited[i] = true;
			func(k + 1);
			visited[i] = false;
		}
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