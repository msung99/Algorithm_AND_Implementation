#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int res = 0;
    while(n--) {
        int data;
        cin >> data;
        res += data;
    }
    cout << res;

    return 0;
}