#include <bits/stdc++.h>
using namespace std;

int n, w, l;
queue<int> truck;
int bridge[102];

bool isBridgeEmpty() {
    for(int i=0; i<w; i++) {
        if(bridge[i] != 0) return false;
    }
    return true;
}

int getCurBridgeTruckWeight() {
    int weight = 0;
    for(int i=0; i<w; i++) {
        weight += bridge[i];
    }
    return weight;
}

int move() {
    int lastBridgeTruckWeight = bridge[w-1];
    for(int i=w-1; i>0; i--) {
        bridge[i] = bridge[i-1];
    }
    bridge[0] = 0;
    return lastBridgeTruckWeight;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> l;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        truck.push(data);
    }

    int ans = 0;
    do {
        int tmp = getCurBridgeTruckWeight();
        int quitBridgeTruckWeight = move(); // 트럭들이 이동시킴
        tmp = tmp - quitBridgeTruckWeight; // 다리의 맨 마지막 칸에 위치한 트럭의 무게(quitBridgeTruckWeight) 를 기존 무게에서 뺀다.

        // 아직 다리위에 올라가지 못한 트럭이 있으며 && 다리 최대허용 무게를 초과하지 않는다면
        if(!truck.empty() && tmp + truck.front() <= l) {
            bridge[0] = truck.front();
            truck.pop();
        }
        ans++;
    } while(!isBridgeEmpty());

    cout << ans;

    return 0;
}