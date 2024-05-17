#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    unordered_set<string> s;

    while(t--) {
        string name, status;
        cin >> name >> status;

        if(status == "enter") {
            s.insert(name);
        } else if(status == "leave") {
            s.erase(name);
        }
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());

    for(auto e : ans) {
        cout << e << "\n";
    }

    return 0;
}