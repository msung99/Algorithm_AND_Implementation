#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<int> dic;

    int n, m;
    cin >> n >> m; // 4, 10

    int res = -1;
    for(int i=1; i<=m; i++) {
        int data;
        cin >> data;
        dic.insert(data);

        if(dic.size() == n) {
            res = i;
            break;
        }

        if(i == m) {
            break;
        }
    }

    cout << res;

    return 0;
}