#include <bits/stdc++.h>
using namespace std;

int k, l;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> l;

    unordered_map<string, int> dic;

    for(int i=1; i<=l; i++) {
        string input;
        cin >> input;
        dic[input] = i;
    }

    vector<pair<string,int>> arr(dic.begin(), dic.end());
    sort(arr.begin(), arr.end(), cmp);

    int cnt = 0;
    for(auto& element : arr) {
        if(cnt == k) {
            break;
        }
        cnt++;
        cout << element.first << "\n";
    }

    return 0;
}