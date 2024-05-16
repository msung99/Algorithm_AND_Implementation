#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[502];
bool visited[502];
int treeCnt;
bool isTree;

void dfs(int cur, int prev) {
    for(int next : adj_list[cur]) {
        // next가 부모(prev)일 경우 건너뜀
        if(next == prev) {
            continue;
        }

        // 트리일 경우 자식은 반드시 이전에 방문한 적이 없었어야 하고, 
        // 이전에 방문을 했다면 현재 보고 있는 connected component가 사이클이 존재하여 트리가 아님을 의미.
        if(visited[next]) {
            isTree = false;
            continue; // 주의: 트리가 아님이 판명되는 즉시 return 하는게 아니라, 같은 사이클 내에 존재하는
            // 다른 모든 정점들에 대해 vistied 를 true 로 처리해줘야함. 이 작업을 위해 즉시 return 하지 않고 continue 처리함
        }
        visited[next] = true;
        dfs(next, cur);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int round = 1;
    while(true) {
        cin >> n >> m;

        if(n == 0 && m == 0) {
            break;
        }

        fill(visited + 1, visited+n+1, false);
        for(int i=1; i<=n; i++) {
            adj_list[i].clear();
        }

        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }        

        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                isTree = true;
                dfs(i, -1);
                
                if(isTree) {
                    treeCnt++;
                }
            }
        }

        cout << "Case " << round << ": ";
        if(treeCnt == 0) {
            cout << "No trees.\n";
        } else if(treeCnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
        treeCnt = 0;
        round++;
    }

    return 0;
}