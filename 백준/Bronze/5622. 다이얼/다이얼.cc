#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int res = 0;
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(c == 'A' || c == 'B' || c == 'C') {
            res += 3;
        } else if(c == 'D' || c == 'E' || c == 'F') {
            res += 4;
        } else if(c == 'G' || c == 'H' || c == 'I') {
            res += 5;
        } else if(c == 'J' || c == 'K' || c == 'L') {
            res += 6;
        } else if(c == 'M' || c == 'N' || c == 'O') {
            res += 7;
        } else if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
            res += 8;
        } else if(c == 'T' || c == 'U' || c == 'V') {
            res += 9;
        } else if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
            res += 10;
        } 
    }
    cout << res;

    /* int res = 0;
    for(int i=0; i<s.size(); i++) {
        res += (s[i] - 'A' + 6) / 3 + 1;
    }
    cout << res; */

    return 0;
}