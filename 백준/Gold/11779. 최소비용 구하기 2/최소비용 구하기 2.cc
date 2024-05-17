#include <bits/stdc++.h>
using namespace std;

int v, e, st, en;
vector<pair<int,int>> adj_list[1005];
int d[1005]; // 최단 경로 테이블
int pre[1005]; // pre[i] : 노드 i의 직전에 방문했던 노드 번호 테이블
const int infinite = 1999999999;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    fill(d, d + v + 1, infinite);

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
    }

    cin >> st >> en;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    d[st] = 0;
    pq.push({d[st], st});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(d[cur.second] != cur.first) {
            continue;
        }

        for(auto next : adj_list[cur.second]) {
            if(d[next.second] <= d[cur.second] + next.first) {
                continue;
            }
            d[next.second] = d[cur.second] + next.first; 
            pq.push({d[next.second], next.second});
            pre[next.second] = cur.second; // 최단 거리값 갱신이 일어날때 pre 값을 바꿔준다.
        }
    }

    cout << d[en] << "\n";

    // 경로 복원
    vector<int> path;
    int cur = en;
    while(cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }

    path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    
    for(auto x : path) {
        cout << x << ' ';
    }

    return 0;
}