#include <bits/stdc++.h>
using namespace std;

int n, m, r;
const int infinite = 987987987;

int item[102];
bool visited[102];

int d[102][102];
int nxt[102][102];

void visit(int i, int j) {
    int cur = i;
    while(cur != j) {
        visited[cur] = true;
        cur = nxt[cur][j];
    }
    visited[j] = true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) {
        int data;
        cin >> data;
        item[i] = data;
    }

    for(int i=1; i<=n; i++) {
        fill(d[i], d[i]+n+1, infinite);
        d[i][i] = 0;
    }

    int x, y, dist;
    while(r--) {
        cin >> x >> y >> dist;
        d[x][y] = dist;
        d[y][x] = dist;
        nxt[x][y] = y;
        nxt[y][x] = x;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int tmp = d[i][k] + d[k][j];
                if(tmp < d[i][j]) {
                    d[i][j] = tmp;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    int ans = 0;
    int tmp;

    for(int i=1; i<=n; i++) {
        tmp = 0;
        fill(visited+1, visited+n+1, false);

        for(int j=1; j<=n; j++) {
            if(d[i][j] > m) {
                continue;
            }
            visit(i, j);
        }

        for(int j=1; j<=n; j++) {
            if(visited[j]) {
                tmp += item[j];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;

    return 0;
}