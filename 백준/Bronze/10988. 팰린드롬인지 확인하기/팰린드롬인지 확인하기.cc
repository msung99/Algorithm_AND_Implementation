#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    string temp = str; 
    reverse(temp.begin(), temp.end());

    if(temp == str) {
        cout << 1;
    } else {
        cout << 0;
    }
}