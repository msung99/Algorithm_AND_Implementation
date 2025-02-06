#include <bits/stdc++.h>
using namespace std;

int v, e, st;
vector<pair<int,int>> adj_list[20005]; // {가중치, 정점 번호}
int dist[20005]; // 최단 거리 테이블
int infinite = 1999999999;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e >> st;

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
    }

    fill(dist, dist+v+1, infinite);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[st] = 0;
    pq.push({dist[st], st}); // 1. 우선순위 큐에 {0, 시작점} 추가

    // 매번 아직 거리가 확정되지 않은 정점을 중에서 가장 가까운 정점을 찾아 거리를 확정함.
    while(!pq.empty()) {
        // 2-1. 우선순위 큐에서 거리가 가장 작은 원소를 선택함
        auto cur = pq.top();  // {가중치, 정점 번호}
        pq.pop();

        // 2-2. 이미 최소 거리값을 확정한 정점인 경우 (선택한 원소의 거리값이 최단 거리 테이블에 있는 값과 다를 경우) continue
        if(dist[cur.second] != cur.first) {
            continue;
        }

        // 3. 정점 cur과 이웃한 정점(next)들에 대해 최단거리 테이블 값보다 
        // cur 을 거쳐가는 것이 더 효율적인(작은) 최단 거리 값일 경우
        // next 의 최단거리 테이블 값을 갱신하고 우선순위 큐에 (거리, next) 를 추가
        for(auto next : adj_list[cur.second]) {
            // 특정 정점의 거리가 확정됐는지 여부를 저장하기 않기 때문에, 매번 거리를 비교해야 함

            // 기존에 next 에 계산된 최소 거리값(= d[next.second]) 이 현재 계산된 거리값보다 더 클 경우 continue
            // => ex) 기존에 계산된 정점 next 의 거리값이 무한대(infinfie) 이고,
            // 현재 cur 을 통해 next 로 거쳐가는 값이 3이라면,
            // 정점 next 에 도달 가능한 거리값 중에 현재까지 계산된 최소 거리값이 3이다.
            if(dist[next.second] <= dist[cur.second] + next.first) {
                continue;
            }

            // d[next.second] 를 갱신하고 우선순위 큐에 (거리, next.second) 를 추가한다.
            dist[next.second] = dist[cur.second] + next.first;
            pq.push({dist[next.second], next.second});
        }
    }

    for(int i=1; i<=v; i++) {
        if(dist[i] == infinite) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}