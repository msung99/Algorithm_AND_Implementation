#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[100002];
bool visited[100002];
double mx;
vector<int> computers;
int mini;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = true;

    double vertex_cnt = 0;
    double edge_cnt = 0;

    vector<int> tmp;
    tmp.push_back(st);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        vertex_cnt++;

        for(int next : adj_list[cur]) {
            edge_cnt++;
            if(visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);
            tmp.push_back(next);
        }
    }    
    double res = edge_cnt / vertex_cnt;

    if(res > mx) {
        mx = res;
        computers.clear();
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<tmp.size(); i++) {
            computers.push_back(tmp[i]);
        }
        mini = computers.front();
    } else if(res == mx) { // 밀도가 같은게 여러개라면
        if(tmp.size() == computers.size()) { // 컴퓨터 수가 같은게 여러개라면
            sort(tmp.begin(), tmp.end());
            if(mini > tmp.front()) { // 더 작은 컴퓨터 번호를 가졌다면
                computers.clear();
                for(int i=0; i<tmp.size(); i++) {
                    computers.push_back(tmp[i]);
                }
            }
        } else {
            if(tmp.size() < computers.size()) { // 컴퓨터 수가 더 작은 컴포넌트라면
                sort(tmp.begin(), tmp.end());
                computers.clear();
                for(int i=0; i<tmp.size(); i++) {
                    computers.push_back(tmp[i]);
                }
            }
        }
    }
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }

    for(int i=0; i<computers.size(); i++) {
        cout << computers[i] << ' ';
    }

    return 0;
}