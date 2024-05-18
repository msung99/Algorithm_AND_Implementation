#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj_list[100002];
int subTreeCnt[100002];
bool visited[100002];

int addSubTreeCnt(int cur) {
    visited[cur] = true;

    for(int next : adj_list[cur]) {
        if(visited[next]) {
            continue;
        }
        subTreeCnt[cur] += addSubTreeCnt(next);
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

    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    addSubTreeCnt(r);    

    while(q--) {
        int root;
        cin >> root;
        cout << subTreeCnt[root] << "\n";
    }

    return 0;
}