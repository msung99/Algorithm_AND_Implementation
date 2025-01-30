#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int res[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int lastNum = 0;
    for(int i=0; i<n; i++) {
        if(num[i] != lastNum) {
            res[k] = num[i];
            lastNum = num[i];
            func(k+1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);

    func(0);

    return 0;
}