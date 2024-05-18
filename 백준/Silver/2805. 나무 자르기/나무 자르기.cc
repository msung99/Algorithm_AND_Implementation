#include <bits/stdc++.h>
using namespace std;

int n, m;
int tree[1000002];

// x만큼 잘라냈을 때 남는 나무의 길이가 m 이상인가?
bool solve(int x) {
    long long cur = 0;
    for(int i=0; i<n; i++) {
        if(tree[i] <= x) {
            continue;
        }
        cur += (tree[i] - x);
    }
    return cur >= m;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> tree[i];
    }

    int st = 0;
    int en = *max_element(tree, tree + n);

    while(st < en) {
        int mid = (st+en+1) / 2;
        if(solve(mid)) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }

    cout << st;

    return 0;
}