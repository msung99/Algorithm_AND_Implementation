#include <bits/stdc++.h>
using namespace std;

int n, t;
unordered_map<string, int> dic;
unordered_map<int, string> num;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;

        dic[s] = i;
        num[i] = s;
    }

    while(t--) {
        string s;
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9') {
            cout << num[stoi(s)] << "\n";
        } else {
            cout << dic[s] << "\n";
        }
    }

    return 0;
}