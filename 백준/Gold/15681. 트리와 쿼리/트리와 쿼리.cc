#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;

int n, r, query;
vector<vector<int>> adj_list;
vector<int> nodenum;

// 트리 정보를 입력받고 쿼리를 입력받기전에, 루트를 시작으로 DFS 를 해서,
// 모든 노드에 대해 자신을 루트로 하는 트리의 정점의 개수를 구할 수 있다.

// DFS 를 통해 자식이 없는 리프노드까지 도달한 뒤, 해당 리프노드를 기준으로 하는 트리에서는 정점이 당연히 1개일 것이고,
// DFS 를 반환하면서 (부모로 올라감) 자신의 자식을 서브트리의 루트로 하는 서브트리의 정점의 수 + 1(자기 자신) 
// 이런 방식으로 거슬러 올라간다.

int DFS(int parent, int cur)
{
	// 리프노드의 도달할 경우 서브트리의 노드의 개수(sub_tree_num)는 0이 될 것이다.
	int sub_tree_num = 0;
	for (int nxt : adj_list[cur]) // cur 와 인접한 모든 노드들에 대해 살펴보면서
	{
		if (nxt == parent)  // cur 과 인접한 노드인 nxt 가 부모노드인 경우
			continue; // 부모 노드로 이동해서 탐색을 이어가면 안되므로, 스킵

		sub_tree_num += DFS(cur, nxt); // 재귀호출 => cur : 부모노드(parent),  nxt : 자식노드(cur) 로 할당
	}
	return nodenum[cur] = sub_tree_num + 1;  // 서브트리의 노드의 개수로 본인까지 1 더해서 게산
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> query;
	adj_list.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	nodenum.resize(n + 1);
	DFS(0, r); // 전체트리의 루트 노드인 r 을 시작으로 DFS 탐색

	for (int j = 0; j < query; j++) {
		int subroot;
		cin >> subroot;
		cout << nodenum[subroot] << '\n';
	}
}