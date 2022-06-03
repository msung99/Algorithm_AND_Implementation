#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int main(void)
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n, m, question;
		cin >> n >> m >> question;

		vector<int> adj_list[201];
		bool visited[201];
		int max_list[201];  
		
		fill(visited + 1, visited + n + 1, false);

		for (int i = 0; i < 201; i++)
			max_list[i] = -1;

		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		// BFS
		for (int i = n; i >= 1 ; i--)  // 최솟값 구할때랑 다른점 <=> for문을 거꾸로 돌려야함!  
		{                              // 거꾸로 돌려야지 해당 정점이, 속해있는 connected 컴포넌트에서 자기가 최댓값이 되고 그 connected 컴포넌트의 다른 정점들에게 자신의 값인 최댓값이 전파가 된다
			if (visited[i]) 
				continue;  

			queue<int> q;
			q.push(i);
			visited[i] = true;

			int max = q.front(); 

			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto nxt : adj_list[cur])
				{
					if (visited[nxt])
						continue;
					
					if (max < nxt)
						max = nxt;
					q.push(nxt);
					visited[nxt] = true;
					
					max_list[nxt] = max;
				}
				max_list[i] = max; 
			}
		}

		while (question--)
		{
			int ans;
			cin >> ans;
			cout << max_list[ans] << endl;
		}
	}
}