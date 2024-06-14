#include <bits/stdc++.h>
using namespace std;

int n, k;
char board[502][502];
int dist[502][502];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> board[i][j];
		}
	}
	
	while(k--) {
		int x, y;
		cin >> x >> y;
		
		if(board[x][y] == '0') {
				dist[x][y] += 1;
		}
		
		if(board[x][y] == '@') {
			dist[x][y] += 2;
		}
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(board[nx][ny] == '0') {
				dist[nx][ny] += 1;
			}
			if(board[nx][ny] == '@') {
				dist[nx][ny] += 2;
			}
		}
	}
	
	int mx = -1999999999;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			mx = max(mx, dist[i][j]);
		}
	}
	cout << mx;
	
	return 0; 
}