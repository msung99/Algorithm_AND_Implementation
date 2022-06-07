#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<int> adj_list[2001];
	
	int t, n, a;
	cin >> t >>  n;
	for (int i = 0; i < n; i++)  // 이 문제를 풀때 정점의 정보를 입렫받을 필요가 없다. 입력받은 정점의 정보는 걍 무시하자! 쓸모없음
	{
		cin >> a;  // a는 입력값을 처리해줄 임시변수. (쓸모없는 입력값들 처리)
	}
	while (t--)
	{

		string a;
		cin >> a;
		if (a == "insertEdge")
		{
			int u, v;
			int check = 0;
			cin >> u >> v;

			for (int i = 0; i < adj_list[u].size(); i++)  // 두 정점을 잇는 간선이 이미 존재하는지 체크
			{
				if (adj_list[u][i] == v)  // 정점 (u, v) 가 이미 존재하는 경우
				{
					cout << "Exist" << endl;
					check = 1;
				}
			}
			if (check == 0)
			{
				adj_list[u].push_back(v);
				adj_list[v].push_back(u);
			}
		}
		else if (a == "eraseEdge")
		{
			int u, v;
			int check = 0;
			int index = 0;
			cin >> u >> v;

			for (int i = 0; i < adj_list[u].size(); i++)  // 두 정점을 잇는 간선 (u, v) 가 존재하는지 찾는 과정
			{
				 // 두 정점을 잇는 간선 (u, v) 가 존재한다면 
				if (adj_list[u][i] == v)
					check = 1;
			}
			
			// 두 정점을 잇는 간선 (u, v) 가 존재한다면 삭제함
			if (check == 1)
			{
				// 삭제할 정점이 각 인접리스트에서 몇번째 인덱스에 저장되어 있는지를 계산
				// 
				// => find(adj_list[u].begin(), adj_list[u].end(), v) : adj_list[u] 벡터에서 데이터 v 의 인덱스 이터레이터를 리턴.
				// 데이터 v의 인덱스 값을 얻어내고 싶다면, 결과값을 begin() 으로 빼야함 
				int index1 = find(adj_list[u].begin(), adj_list[u].end(), v) - adj_list[u].begin();
				int index2 = find(adj_list[v].begin(), adj_list[v].end(), u) - adj_list[v].begin();

				adj_list[u].erase(adj_list[u].begin() + index1);   // 삭제
				adj_list[v].erase(adj_list[v].begin() + index2);
			}
			// 존재하지 않는다면
			else
			{
				cout << "None" << endl;
			}
		}
		else if (a == "SumAdjacentNode")
		{
			int v;
			cin >> v;
			int sum = 0;
			int check = 0;

			if (adj_list[v].size() == 0)  // 정점 v 와 연결된 정점이 존재하지 않는 경우
			{
				cout << "None" << endl;
				check = 1;
			}

			if (check == 0)
			{
				for (int i = 0; i < adj_list[v].size(); i++)
				{
					sum += adj_list[v][i];
				}
				cout << sum << endl;
			}
		}
	}
}