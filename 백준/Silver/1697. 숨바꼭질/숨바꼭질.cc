#include <bits/stdc++.h>
using namespace std;

int st, en;
int dist[100002];

void bfs() {
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : {cur+ 1, cur-1, cur*2}) {
            if(next < 0 || next > 100000) {
                continue;
            }

            if(dist[next] != -1) {
                continue;
            }

            dist[next] = dist[cur] + 1;
            q.push(next);
         }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> st >> en;
    
    fill(dist, dist + 100001, -1);
    bfs();

    cout << dist[en];

    return 0;
}