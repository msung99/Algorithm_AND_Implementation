#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[1002][1002];
bool visited[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int res[32];

void bfs(int sx, int sy) {
	queue<pair<int,int>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	
	int area = 0;
	while(!q.empty()) {
		area++;
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			
			if(board[nx][ny] != board[x][y] || visited[nx][ny]) {
				continue;
			}
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	
	if(area >= k) {
		res[board[sx][sy]]++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	
	int mx = 0;
	int ans = 0;
	for(int i=1; i<=30; i++) {
		if(res[i] >= mx) {
			mx = res[i];
			ans = i;
		}
	}
	cout << ans;
		
	return 0;
}