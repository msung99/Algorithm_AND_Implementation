#include <bits/stdc++.h>
using namespace std;

int board[501][501];
bool vistied[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m; 

// 1. 상하좌우로 연결된 그림의 크기를 찾아내기
// 2. 도화지에 있는 모든 그림을 찾아내기

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int count = 0;
	int max_area = 0;
	int area_count = 0;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (board[i][j] == 0 || vistied[i][j])
				continue;

			area_count++;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vistied[i][j] = true;
			while (!q.empty()) 
			{
				pair<int, int> cur = q.front();
				q.pop();

				count++;
				
				// 4방향으로 뻗음
				for (int k = 0; k < 4; k++) 
				{
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;

					if (vistied[nx][ny] || board[nx][ny] == 0)
						continue;

					q.push({ nx,ny });
					vistied[nx][ny] = true;
				}
			}
			max_area = max(max_area, count);
			count = 0;
		}
	}
	cout << area_count << '\n' << max_area;
}