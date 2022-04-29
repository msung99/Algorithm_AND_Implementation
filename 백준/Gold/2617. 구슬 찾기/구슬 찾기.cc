#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
정방향, 역방향 DFS를 각각 진행했을때 자신의 순서가 중간순서 번호보다 크다면 중간 순서가 될 수 없다.
=> 무게 정보를 보면 간선이 한 방향이다. 이렇게 주어졌기 떄문에 나보다 가벼운 것만 알 수 있다.
   따라서 인접 리스트를 하나 더 만들고 간선을 거꾸로 넣어준다. (결과적으로 DFS를 정방향, 역방향으로 2번 탐색함)
*/

vector<int> adj_list[100]; // 정방향 인접리스트 
vector<int> reverse_adj_list[100]; // 역방향 인접리스트
bool visited[100]; // 정방향 인접리스트의 DFS 방문여부 체크
bool r_visited[100]; // 역방향 인접리스트의 DFS 방문여부 체크
int n, m, u, v;
int cnt, rev_cnt; // 정방향, 역방향 순회할때 카운팅 변수
int result, mid;



void DFS(int node)
{
	stack<int> s;
	s.push(node);
	visited[node] = true;
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		for (auto nxt : adj_list[cur])
		{
			if (visited[nxt])
				continue;

			s.push(nxt);
			visited[nxt] = true;
			cnt++;
		}
	}
}


void rDFS(int node)
{
	stack<int> s;
	s.push(node);
	r_visited[node] = true;
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		for (auto nxt : reverse_adj_list[cur])
		{
			if (r_visited[nxt])
				continue;

			s.push(nxt);
			r_visited[nxt] = true;
			rev_cnt++;
		}
	}
}


int main(void)
{
	cin >> n >> m;
	mid = (n + 1) / 2; // 무게 중간순서 계산

	// 정방향,역방향 인접 리스트에 정보 입력
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		reverse_adj_list[v].push_back(u);
	}

	// DFS 탐색
	for (int i = 1; i <= n; i++)
	{
		// DFS 수행전에 방문 기록 초기화
		cnt = 0;
		rev_cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			visited[i] = false;
			r_visited[i] = false;
		}
		
		// 각 정점마다 DFS 수행
		DFS(i);
		rDFS(i);

		// 정방향, 역방향 순회 결과
		if (cnt >= mid || rev_cnt >= mid)
			result++;
	}
	cout << result;
}