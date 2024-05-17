#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        unordered_map<string, int> dic;
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;
            dic[b]++;
        }

        int res = 1;
        for(auto cloth : dic) {
            res *= (cloth.second + 1);
        }
        cout << res -1 << "\n";
    }

    return 0;
}