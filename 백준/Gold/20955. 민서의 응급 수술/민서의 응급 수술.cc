#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[100002];
bool vistied[100002];

void dfs(int cur) {
    if(vistied[cur]) {
        return;
    }
    vistied[cur] = true;
    for(auto next :adj_list[cur]) {
        dfs(next);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int groupCnt = 0;
    for(int i=1; i<=n; i++) {
        if(vistied[i]) {
            continue;
        }
        dfs(i);
        groupCnt++;
    }

    cout << (groupCnt -1) + (m+groupCnt-1) - (n-1);
    // groupCnt = 연결 요소의 개수
    // (groupCnt-1) 개의 간선을 추가해 주어진 그래프를 연결 그래프로 만들면,
    // 현재 그래프에는 (m+groupCnt-1) 개의 간선이 있고 트리는 n-1개의 간선이 있기 때문애 (m+groupCnt-1) - (n-1)개의 간선을 제거해야 한다.

    return 0;
}