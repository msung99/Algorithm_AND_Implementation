#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj_list[1002];
const int infinite = 1999999999;

int djikstra(int st, int en) {
    int d[1002];
    fill(d, d+n+1, infinite);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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
        }
    }
    return d[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int en;
    cin >> n >> m >> en;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
    }

    int ans = 0;
    for(int st=1; st <= n; st++) {
        ans = max(ans, djikstra(st, en) + djikstra(en, st));
    }

    cout << ans;

    return 0;
}