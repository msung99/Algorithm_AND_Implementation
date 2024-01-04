#include <bits/stdc++.h>
using namespace std;

int cnt[101];
int res;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin >> a >> b >> c;

    for(int i=0; i<3; i++) {
        int start, end;
        cin >> start >> end;
        for(int j = start; j < end; j++) {
            cnt[j]++;
        }
    }

    for(int i=0; i<=100; i++) {
        if(cnt[i] == 1) {
            res += a;          
        } else if(cnt[i] == 2) {
            res += b * 2;
        } else if(cnt[i] == 3) {
            res += c * 3;
        }
    }
    cout << res;
    return 0;
}