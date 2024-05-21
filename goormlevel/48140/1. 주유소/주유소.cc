#include <bits/stdc++.h>
using namespace std;

long long n;
long long road[100002];
long long city[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(long long i=0; i<n-1; i++) {
        cin >> road[i];
    }

    for(long long i=0; i<n; i++) {
        cin >> city[i];
    }

    long long total = 0;
    long long cur_city_idx = 0;

    for(long long i=0; i<n-1; i++) {
        if(city[cur_city_idx] > city[i]) {
            cur_city_idx = i;
            total += city[cur_city_idx] * road[cur_city_idx];
        } else {
            total += city[cur_city_idx] * road[i];
        }
    }
    cout << total;

    return 0;
}