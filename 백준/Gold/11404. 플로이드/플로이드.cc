#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[105][105]; // d[i][j] : 정점 i에서 j로 가는 거리 최솟값
const int infinite = 0x3f3f3f3f;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        fill(d[i], d[i]+n+1, infinite);
    }

    while(m--) {
        int a, b, c; // 시작점, 도착점, 비용
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c); // 문제 조건에 따라, 시작점과 도착점을 연결하는 간선은 여러개일 수도 있다고 했으므로
        // 단순히 d[a][b] = c 로 두면 안되고, min() 함수를 통해 간선이 여러개일 경우 가장 작은 간선의 거리가 저장되게 끔 해야한다.
    }

    for(int i=1; i<=n; i++) {
        d[i][i] = 0; // 자기 자신으로 가는 비용은 모두 0으로 만들어 놓는다.
    }

    // 플로이드 알고리즘 시작
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) { // i: 시작점, j: 끝점
            for(int j=1; j<=n; j++) { // 유의할 점 : 테이블을 갱신할 때 중간에 거쳐가게 끔 할 원소를 3중 for문의 가장 바깥에 두어야한다.
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(d[i][j] == infinite) {
                cout << "0 ";
            } else {
                cout << d[i][j] << ' ';
            }
        }
        cout << "\n";
    }

    return 0;
}