#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;

    if(str.find("12") != string::npos 
    && str.substr(str.find("12") + 2).find("21") != string::npos 
    || 
    str.find("21") != string::npos && 
    str.substr(str.find("21") + 2).find("12") != string::npos) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}