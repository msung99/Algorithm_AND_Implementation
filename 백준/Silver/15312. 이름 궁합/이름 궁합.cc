#include <bits/stdc++.h>
using namespace std;

string s[2];
int p[4002][4002];
int cnt[] = {
    3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0]; // CJM
    cin >> s[1]; // HER

    int cur_idx = 0;
    int size = s[0].size();

    for(int i=0; i<size; i++) {
        p[cur_idx++][0] = cnt[s[0][i] - 'A'];
        p[cur_idx++][0] = cnt[s[1][i] - 'A'];
    }

    int len = size * 2;
    int cycle = len - 2;
    for(int cur = 0; cur < cycle; cur++) {
        len--;
        for(int i=0; i<len; i++) {
            p[i][cur+1] = (p[i][cur] + p[i+1][cur]) % 10;
        }
    }
    cout << p[0][size*2 - 2] << p[1][size*2 - 2];

    return 0;
}