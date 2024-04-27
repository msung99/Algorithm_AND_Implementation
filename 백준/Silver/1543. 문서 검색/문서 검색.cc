#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    int cnt = 0;
    int f = str1.find(str2);

    while(f != string::npos) {
        cnt++;
        f = str1.find(str2, f + str2.size());
    }

    cout << cnt;

    return 0;
}