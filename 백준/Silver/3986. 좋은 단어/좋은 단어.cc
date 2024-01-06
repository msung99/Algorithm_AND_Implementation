#include <bits/stdc++.h>
using namespace std;

int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;

        stack<char> s;
        for(int i=0; i<str.size(); i++) {
            if(s.empty()) {
                s.push(str[i]);
            } else if(s.top() == str[i]) {
                s.pop();
            } else {
                s.push(str[i]);
            }
        }   
        if(s.empty()) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}