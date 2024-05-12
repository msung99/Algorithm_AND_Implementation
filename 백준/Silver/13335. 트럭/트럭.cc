#include <bits/stdc++.h>
using namespace std;

int n, w, l;
queue<int> truck;
int bridge[1002];

bool isBridgeEmpty() {
    for(int i=0; i<w; i++) {
        if(bridge[i] != 0) {
            return false;
        }
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
    int lastQuitTruckWeight = bridge[w-1];
    for(int i=w-1; i>0; i--) {
        bridge[i] = bridge[i-1];
    }
    bridge[0] = 0;
    return lastQuitTruckWeight;
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
        ans++;
        int tmp = getCurBridgeTruckWeight();
        int lastQuitTruckWeight = move();
        tmp = tmp - lastQuitTruckWeight;
        if(!truck.empty() && tmp + truck.front() <= l) {
            bridge[0] = truck.front();
            truck.pop();
        }
    } while(!isBridgeEmpty());

    cout << ans;

    return 0;
}