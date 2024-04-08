#include <bits/stdc++.h>
using namespace std;

int n, money;
int arr[1000003];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> money;

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int i=n; i>0; i--) {
        while(true) {
            if(money - arr[i] >= 0) {
                money = money - arr[i];
                cnt++;
            } else {
                break;
            }
        }
    }

    cout << cnt;


    return 0;
}