#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[10002];
int arr[10002];
bool visited[10002];

int bfs(int st) {
    fill(visited, visited +n+2, false);
    queue<int> q;
    q.push(st);
    visited[st] = true;

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for(int next : adj_list[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj_list[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        arr[i] = bfs(i);        
    }
    int maxVal = *max_element(arr+1, arr+n+1);
    for(int i=1; i<=n; i++) {
        if(arr[i] == maxVal) {
            cout << i << ' ';
        }
    }

    return 0;
}