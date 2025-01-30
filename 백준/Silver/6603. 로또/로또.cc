#include <bits/stdc++.h>
using namespace std;

int n;
int num[15];
int res[15];

void func(int k, int st) {
    if(k == 6) {
        for(int i=0; i<6; i++) {
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=st; i<n; i++) {
        res[k] = num[i];
        func(k+1, i+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        cin >> n;

        if(n == 0) {
            break;
        }

        for(int i=0; i<n; i++) {
            cin >> num[i];
        }
        func(0, 0);
        cout << "\n";
    }

    return 0;
}