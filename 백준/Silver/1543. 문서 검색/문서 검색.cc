#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, tmp;
    getline(cin, s);
    getline(cin, tmp);

    int cnt = 0;
    int pos = s.find(tmp);

    while(pos != string::npos) {
        cnt++;
        pos = s.find(tmp, tmp.size() + pos);        
    }

    cout << cnt;

    return 0;
}