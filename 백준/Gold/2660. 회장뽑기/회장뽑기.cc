#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj_list[51];
int dist[51];
int score_list[51];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int score = 0; // 회원의 점수
	int n;
	cin >> n;
	int u, v;
	while (true)
	{
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	// BFS 탐색
	for (int i = 1; i <= n; i++)
	{
		fill(dist, dist + n + 1, -1);
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto nxt : adj_list[cur])
			{
				if (dist[nxt] != -1)
					continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}

		// 한 정점(회원)에 대한 BFS 탐색후 dist에 거리에 대한 정보가 저장되면, 그 회원에 대한 점수를 계산한다. 
		for (int k = 1; k <= n; k++)
		{
			if (score < dist[k])
				score = dist[k];
		}
		score_list[i] = score;
		score = 0;
	}

	int last_score = 99999; // 회장 후보의 점수
	int count = 0; // 회장 후보의 수
	for (int i = 1; i <= n; i++)
	{
		if (last_score > score_list[i])
			last_score = score_list[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (last_score == score_list[i])
			count++;
	}
	
	cout << last_score << ' ' << count << '\n';
	// 회장 후보를 오름차순으로 모두 출력
	for (int i = 1; i <= n; i++)
	{
		if (last_score == score_list[i])
			cout << i << ' ';
	}
}