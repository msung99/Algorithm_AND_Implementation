/*
자식 노드의 개수를 세는 벡터를 생성합니다.
데이터가 들어오면 자식 노드의 개수를 전부 입력받습니다.

제거하는 노드의 번호를 받고, 자식 노드의 숫자를 확인하면서 dfs를 수행합니다.
dfs를 수행하면서 탐색하는 노드가 제거된 노드이면 리턴해줍니다.

그 다음으로는 자식의 개수에 따라서 달라집니다.
자식이 0개면 리프노드이기 때문에 정답에 1을 더해줍니다.
자식이 1개이면 해당 노드가 제거된 노드이면 리프노드이기 때문에 정답에 +1을 해주고, 아니면 dfs를 진행합니다.
자식이 2개 이상이면 dfs를 각각의 노드에 대하여 수행합니다.

자세한 구현은 소스코드를 참조해주세요~
*/

#include <iostream>
#include <vector>
using namespace std;

int n, k, leaf = 0, root;
vector<int> tree[51];

int dfs(int node) {
	if (node == k) // 
		return -1;

	if (!tree[node].size()) { 
		leaf++;
		return 0;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int tmp = dfs(tree[node][i]);
		if (tmp == -1 && tree[node].size() == 1)
			leaf++;
	}
	return 0;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1;
		cin >> t1;
		if (t1 == -1)
			root = i;
		else
			tree[t1].push_back(i);
	}
	cin >> k;

	dfs(root);
	cout << leaf;
}

/*
#include <bits/stdc++.h>
using namespace std;

int n, del_node;
vector<int> adj[51];
int parent[10];   //  각 정점의 부모 노드를 저장할 배열 p (이때 루트의 부모는 자연스래 0이 된다.)

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//cout << cur << ' ';
		for (int nxt : adj[cur]) {
			if (parent[cur] == nxt)      // 부모일 경우를 바움ㄴ할 필요없으므로 pass
				continue;                 // 부모가 아니면 큐에 넣고 p[nxt] = cur 로 만든다.
			q.push(nxt);
			parent[nxt] = cur;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int node;
		cin >> node;
		if (node == -1)
			continue;
		//adj[i].push_back(node);
		adj[node].push_back(i);
	}
	BFS(0); // 부모 배열 셋팅

	cin >> del_node;

	adj[parent[del_node]].erase(remove(adj[parent[del_node]].begin(), adj[parent[del_node]].end(), del_node));
}

*/