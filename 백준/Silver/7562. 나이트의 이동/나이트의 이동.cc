#include <bits/stdc++.h>
using namespace std;

int n;
int dist[302][302];
int dx[8] = {1,2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            fill(dist[i], dist[i] + n, -1);
        }

        int u, v;
        cin >> u >> v;
        pair<int,int> start = make_pair(u, v);

        cin >> u >> v;
        pair<int,int> end = make_pair(u, v);

        queue<pair<int,int>> q;
        q.push(start);
        dist[start.first][start.second] = 0;

        while(!q.empty()) {
            auto cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();

            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }

                if(dist[nx][ny] != -1) {
                    continue;
                }

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dist[end.first][end.second] << "\n";
    }

    return 0;
}