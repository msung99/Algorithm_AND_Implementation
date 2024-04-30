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
        int n;
        cin >> n;
        unordered_map<string, int> dic;
        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;

            dic[b]++;
        }
        int ans = 1;
        for(auto clothCnt : dic) {
            ans *= (clothCnt.second + 1);
        }
        cout << ans - 1 << "\n";
    }

    return 0;
}