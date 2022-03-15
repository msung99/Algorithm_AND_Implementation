#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> tower; // pair의 first 에는 타워의 높이를, second 에는 타워의 인덱스(몇번째 타워인지) 를 저장
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	tower.push({ 100000001,0 }); // 반복문을 돌리면서 수신받는 타워가 없는 경우 이 가상의 타워가 수신받음. (즉, 수신받는 타워가 존재하지 않는 경우임)

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		// 현태 타워의 높이 height보다 높은 타워를 만날때까지, 현재 타워보다 높이가 작은 타워들을 삭제해 나감 
		// (수신 받을 수 있는 타워를 찾을때까지 탐색)
		while (tower.top().first < height) 
			tower.pop(); // 현재 타워보다 높이가 작은 타워들을 스택에서 제거
		// while문이 끝나고 나면 tower.top() 에 들어있는 것은 현재 타워보다 높이가 높은 타워이다,
		cout << tower.top().second << " ";  

		// 타워 스택 tower에다 현재 타워를 추가
		tower.push({ height,i });
	}
}
