#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    unordered_set<string> dic;

    for(int i=0; i<s.length(); i++) {
        for(int j=i; j<s.length(); j++) {
            string cur = s.substr(i, j-i+1);
            dic.insert(cur);
        }
    }

    cout << dic.size();

    return 0;
}