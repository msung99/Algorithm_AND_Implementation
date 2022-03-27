#include <iostream>
using namespace std;

int num_list[10];
bool visited[10];
int n, m;

void func(int k) // k : 부분 수열에 현재 몇개의 원소가 차있는지
{
	if (k == m) // 부분 수열의 원소를 m개를 다 채웠다면
	{
		for (int i = 0; i < m; i++)
			cout << num_list[i] << ' ';
		cout << '\n';
		return;
	}

	// 이전에 배열에 넣었던 원소 조합들은 다시 배열에 그 조합이 들어가지 않도록 탐색 시작점을 설정
	int start;
	if (k == 0) // k가 0일때, 즉 처음 원소를 넣을때는 시작점을 1로 설정
		start = 1;
	else // k가 0이 아닐때는 가장 최근에 넣었던 원소( = num_list[k-1] ) 보다 큰 원소들에 대해서 num_list에 넣을 수 있는지를 판단
		start = num_list[k - 1] + 1;

	for (int i = start; i <= n; i++)
	{
		num_list[k] = i; // k번쨰 원소를 숫자 i로 설정
		visited[i] = true;
		func(k + 1);
		visited[i] = false;
	}
}


int main(void)
{
	cin >> n >> m;
	func(0);
}