#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[102][102];
int nxt[102][102];
const int infinite = 0x3f3f3f3f;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        fill(dist[i], dist[i]+n+1, infinite);
    }

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        nxt[a][b] = b;
    }

    for(int i=1; i<=n; i++) {
        dist[i][i] = 0;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dist[i][j] == infinite) {
                cout << "0 ";
            } else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << "\n";
    }    

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dist[i][j] == 0 || dist[i][j] == infinite) {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }

            path.push_back(j);
            cout << path.size() << ' ';

            for(auto x : path) { 
                cout << x << ' ';
            }
            cout << "\n";
        }
    }
  
  return 0;
}