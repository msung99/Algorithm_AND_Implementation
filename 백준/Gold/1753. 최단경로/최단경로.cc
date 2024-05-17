// 매번 아직 거리가 확정되지 않은 정점을 중에서 가장 가까운 정점을 찾아 거리를 확정함.
#include <bits/stdc++.h>
using namespace std;

int v, e, st;
vector<pair<int,int>> adj_list[20005]; // {비용, 정점 번호}
int d[20005]; // 최단 거리 테이블
int infinite=1999999999;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e >> st;
    fill(d, d + v + 1, infinite);

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    d[st] = 0;
    pq.push({d[st], st}); // 1. 우선순위 큐에 (0, 시작점) 추가


    while(!pq.empty()) {
        // 2-1. 우선순위 큐에서 거리가 가장 작은 원소를 선택함.
        auto cur = pq.top(); // {비용, 정점 번호}
        pq.pop();

        // 2-2. 거리가 d에 있는 값과 다를 경우 넘어감 (선택한 원소의 거리값이 최단 거리 테이블에 있는값과 다를 경우 넘어감)
        if(cur.first != d[cur.second]) {
            continue;
        }

        // 3. 원소가 가리키는 정점을 v라고할 떄, v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 것이
        // 더 작은 값을 가질경우 최단 거리 테이블의 값을 갱신하고 우선순위 큐에 (거리, 이웃한 정점의 번호) 를 추가
        for(auto next : adj_list[cur.second]) {
            // 특정 정점의 거리가 확정됐는지 여부를 저장히지 않기 때문에 매번 거리를 비교해야함

            // 기존의 next 에 게산된 최소 거리값 ( = d[next.second]) 이 더 현재 계산된 거리값보다 더 클 경우 continue
            // => ex) 기존에 계산된 정점 next 의 거리값이 무한대(infinite) 이고, 현재 cur 에서 거쳐서 가는 값이 3 이라면, 
            // 정점 next 에 도달 가능한 거리값 중에 현재까지 계산된 최솟 거리값이 곧 cur 에서 next 로 이동했 경우의 거리값이므로 이를 기반하여 최신화해준다.
            if(d[next.second] <= d[cur.second] + next.first) {
                continue;
            } 
            // d[next.second] 를 갱신하고 우선순위 큐에 (거리, next.second) 를 추가
            d[next.second] = d[cur.second] + next.first;
            pq.push({d[next.second], next.second});
        }
    }

    for(int i=1; i<=v; i++) {
        if(d[i] == infinite) {
            cout << "INF\n";
        } else {
            cout << d[i] << "\n";
        }
    }

    return 0;
}