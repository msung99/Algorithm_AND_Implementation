#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> dic;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        dic[s1] = s2;
    }

    for(int i=0; i<m; i++) {
        string input;
        cin >> input;

        cout << dic[input] << "\n";
    }

    return 0;
}