#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    unordered_map<string, string> dic;

    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;

        dic[s1] = s2;
    }
    
    while(m--) {
        string s1;
        cin >> s1;

        cout << dic[s1] << "\n";
    }

    return 0;
}