#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans;
int num[22];

void func(int k, int cur) {
    if(k == n) {
        if(cur == s) {
            ans++;
        }
        return;
    }

    func(k+1, cur);
    func(k+1, cur+num[k]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }

    func(0, 0);

    if(s == 0) {
        ans--;
    }

    cout << ans;

    return 0;
}