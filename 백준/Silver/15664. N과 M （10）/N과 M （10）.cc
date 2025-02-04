#include <bits/stdc++.h>
using namespace std;

int num[10];
int res[10];
int n, m;
bool isused[10];

void func(int k, int st) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << res[i] << ' ';
        }        
        cout << "\n";
        return;
    }

    int lastNum = 0;
    for(int i=st; i<n; i++) {
        if(!isused[i] && lastNum != num[i]) {
            isused[i] = true;
            lastNum = num[i];
            res[k] = num[i];
            func(k+1, i+1);
            isused[i] = false;
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
    sort(num, num+n);

    func(0, 0);

    return 0;
}