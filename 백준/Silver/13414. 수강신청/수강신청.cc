#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> dic;

    for(int i=1; i<=m; i++) {
        string input;
        cin >> input;
        dic[input] = i;
    }
    vector<pair<string, int>> arr(dic.begin(), dic.end());
    sort(arr.begin(), arr.end(), cmp);

    int cnt = 0;
    for(auto element : arr) {
        if(cnt == n) {
            break;
        }
        cnt++;
        cout << element.first << "\n"; 
    }

    return 0;
}