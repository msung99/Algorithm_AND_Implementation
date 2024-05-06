#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fill(dist, dist + 100001, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<3; i++) {
            int nx;
            if(i == 0) {
                nx = cur+1;
            } 
            if(i == 1) {
                nx = cur-1;
            }
            if(i == 2) {
                nx = cur*2;
            }

            if(nx < 0 || nx > 100000) {
                continue;
            }

            if(dist[nx] != -1) {
                continue;
            }
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    cout << dist[m];

    return 0;
}