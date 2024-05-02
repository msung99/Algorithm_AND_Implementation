#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj_list[1000002];
bool visited[1000002];
int subTreeCnt[1000002];

int addSubTreeCount(int cur) {
    visited[cur] = true;

    for(auto next : adj_list[cur]) {
        if(visited[next]) {
            continue;
        }
        subTreeCnt[cur] += addSubTreeCount(next);
    }
    subTreeCnt[cur]++;
    return subTreeCnt[cur];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> q;

    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    addSubTreeCount(r);

    for(int i=0; i<q; i++) {
        int root;
        cin >> root;
        cout << subTreeCnt[root] << "\n";
    }

    return 0;
}