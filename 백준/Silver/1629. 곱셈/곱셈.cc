#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll go(ll a, ll b) {
    if(b == 1) {
        return a % c;
    }

    ll result = go(a, b/2);
    result = (result * result) % c;

    if(b % 2 == 1) {
        result = (result * a) % c;
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    cout << go(a, b);
    return 0;
}