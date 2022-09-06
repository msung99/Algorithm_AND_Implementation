#include <bits/stdc++.h>
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
*/
using namespace std;

vector<int> adj_list[100];
int visited[100];

// DFS 탐색이 끝나고 나면, visited에 정점 x에 대해 방문처리된 결과가 저장된다.
void DFS(int x) {
	// 정점 x의 인접 리스트에 담겨있는 정점들에 대한 방문 처리 
	for (int i = 0; i < adj_list[x].size(); i++) { 
		if (!visited[adj_list[x][i]]) 
		{
			visited[adj_list[x][i]] = 1;
			DFS(adj_list[x][i]); // 재귀 호출을 해서 계속 한 방향으로 깊게 쭉 뻗어나가면서 방문 처리 시도
		}
	}
}

int main(void)
{
	int n, vertex;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vertex;
			if (vertex == 1) // 각 정점 i에 대해 연결된 정점 j를 정점 i의 인접 리스트에 push
				adj_list[i].push_back(j);
		}
	}

	// 각 정점들에 대해 실행 
	for (int i = 0; i < n; i++) {
		fill(visited, visited + n, 0); // 다음 정점에 대한 DFS 호출을 해서 방문 정보를 visited 에 담기위해 0으로 초기화
		DFS(i); // DFS 탐색으로 정점 i에 대해 visited 에다 방문처리 정보를 저장한다,

		// 정점 i에 대한 visited 에 방문처리가 완료된 정보를 출력 
		for (int j = 0; j < n; j++) {  
			cout << visited[j] << ' '; 
		}
		cout << '\n';
	}
}
