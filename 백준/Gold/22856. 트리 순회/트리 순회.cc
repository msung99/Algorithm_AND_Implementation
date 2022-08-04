#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
int a = -1, r = -1;
map<int, pair<int, int>> relation; // map 을 이용해서 부모 노드가 갖고있는 자식 노드를 pair<int,int> 를 사용해서
// 왼쪽 자식 노드, 오른쪽 자식 노드를 표현


/*
travel(int, bool) : 탐색함수
탐색을 할떄는 루트 노드부터 시작하고, 해당 노드의 값이 -1일 경우 반환시킨다.
탐색이 시작되면 전체 이동 횟수를 증가시키고 왼쪽 노드를 탐색한다.
여기서 중요한 것은 탐색할 때 bool형 인자값도 전달시키는데 루트 노드에 왼쪽 노드로 탐색할 떄는 
bool값을 false 로 설정해서 왼쪽 노드 탐색에서는 오른쪽 노드의 이동 횟수를 뺴는 것을 배제시켰다.
루트에서 왼쪽 자식노드 탐색이 끝났으면 오른쪽 자식노드를 탐색을 한다.
해당 값부터는 오른쪽 자식노드를 탐색할 때마다 후에 뺄 값을 증가시킨다.
*/

void travel(int cur, bool flag) {
	if (cur == -1)
		return;

	a++;
	travel(relation[cur].first, 0);
	
	if (flag) {
		r++;
		travel(relation[cur].second, 1);
	}
	else
		travel(relation[cur].second, 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0, cur, left, right; i < n; i++) {
		cin >> cur >> left >> right;
		relation[cur].first = left;
		relation[cur].second = right;
	}

	travel(1, 1);

	cout << 2 * a - r;
}