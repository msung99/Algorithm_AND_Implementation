#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> dic1;
unordered_map<int, string> dic2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;

        dic1[str] = i;
        dic2[i] = str;
    }

    for(int i=0; i<m; i++) {
        string a;
        cin >> a;

        if(a[0] >= '0' && a[0] <= '9') {
            cout << dic2[stoi(a)] << "\n";
        } else {
            cout << dic1[a] << "\n";
        }
    }

    return 0;
}