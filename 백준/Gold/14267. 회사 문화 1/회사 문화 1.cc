/*
칭찬받는 노드와 정도를 받을떄마다 DFS를 실행하는 것이 아니라, 해당 정보를 배열에 미리 저장하고 이를 활용한다.

1. 몇번째 노드가 칭찬을 얼마나 받았는지 그 시작점을 우선 배열에 저장한다.
2. 사장(1번노드)이 트리의 root 노드이므로, DFS를 1번 노드부터 시작해서 여태까지 자신이 받은 칭찬의 양을 모든 자식 노드(자손)들에게 더해준다.

이렇게 하면 DFS를 한번 실행하면서도 자손들에게 내리 칭찬을 할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> praise;

void DFS(int cur) {
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		praise[next] += praise[cur];
		DFS(next);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	graph.emplace_back();

	cin >> n >> m;
	graph.assign(n + 1, vector<int>(0, 0));
	praise.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		int superior;
		cin >> superior;
		if (superior != -1)
			graph[superior].emplace_back(i);
	}

	for (int i = 0; i < m; i++) {
		int person, credit;
		cin >> person >> credit;
		praise[person] += credit;
	}

	DFS(1);

	for (int i = 1; i <= n; i++) {
		cout << praise[i] << ' ';
	}
}
