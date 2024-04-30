#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dic;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string name, command;
        cin >> name >> command;
        if(command == "enter") {
            dic.insert(name);
        } else if(command == "leave") {
            dic.erase(name);
        }
    }

    vector<string> res(dic.begin(), dic.end());
    sort(res.rbegin(), res.rend());
    for(auto element : res) {
        cout << element << "\n";
    }

    return 0;
}