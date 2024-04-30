#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> dic;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=1; i<=m; i++) {
        string input;
        cin >> input;

        dic[input] = i;
    }

    vector<pair<string, int>> res(dic.begin(), dic.end());
    sort(res.begin(), res.end(), cmp);

    int cnt = 0;

    for(auto element : res) {
        if(cnt == n) {
            break;
        }
        cnt++;
        cout << element.first << "\n";
    }

    return 0;
}