#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int,int>> fruits;
vector<pair<int,int>> each_prices;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        fruits.push_back({a, b});
    }

    for(int i=0; i<n; i++) {
        int a, b;
        tie(a, b) = fruits[i];
        int each_price = b / a;
        each_prices.push_back({each_price, i});
    }

    sort(each_prices.begin(), each_prices.end(), greater<>());

    int remain_money = k;
    long long ans = 0;
    for(auto cur : each_prices) {
        int each_price = cur.first;
        int i = cur.second;

        int p, c;
        tie(p, c) = fruits[i];

        if(remain_money >= p) {
            ans += c;
            remain_money -= p;
        } else {
            ans += each_price * remain_money;
            break;
        }
    }

    cout << ans;

    return 0;
}