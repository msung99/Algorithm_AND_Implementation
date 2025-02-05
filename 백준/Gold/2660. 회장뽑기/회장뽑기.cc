#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[52];
int dist[52];
int score[52];
int n;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : adj_list[cur]) {
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

    cin >> n;

    while(true) {
        int u, v;
        cin >> u >> v;

        if(u == -1 && v == -1) {
            break;
        }

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        fill(dist, dist + n+1, -1);
        bfs(i);

        int curScore = *max_element(dist+1, dist+n+1);
        score[i] = curScore;
    }

    int minValue = *min_element(score+1, score+n+1);

    vector<int> person;
    for(int i=1; i<=n; i++) {
        if(score[i] == minValue) {
            person.push_back(i);
        }
    }

    cout << minValue << ' ' << person.size() << "\n";
    for(int i=0; i<person.size(); i++) {
        cout << person[i] << ' ';
    }

    return 0;
}