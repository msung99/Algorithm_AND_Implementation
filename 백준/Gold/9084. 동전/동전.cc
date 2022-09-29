#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10005], d[10005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        fill(d, d + 10005, 0);
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cin >> m;
        d[0] = 1;

        for (int i = 0; i < n; i++) // 각 동전에 대해
            for (int j = a[i]; j <= m; j++)
                d[j] += d[j - a[i]];  // 금액 j를 만들 수 있는 경우의수  = (기존 금액 j 경우의 수) + (

        cout << d[m] << '\n';
    }
}