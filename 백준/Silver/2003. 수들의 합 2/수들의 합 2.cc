#include <bits/stdc++.h>
using namespace std;

int n, m;
long long prefix_sum[10002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    prefix_sum[0] = 0;

    for(int i=1; i<=n; i++) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }

    int cnt = 0;
    int st = 0, en = 0;
    while(en <= n && st <= n) {
        long long cur_sum = prefix_sum[en] - prefix_sum[st];
        if(cur_sum <= m) {
            if(cur_sum == m) {
                cnt++;            
            }
            if (en < n) {
                en++;
            } else {
                break;
            }
        } 
        else {
            st++;
        }
    }

    cout << cnt;

    return 0;
}
