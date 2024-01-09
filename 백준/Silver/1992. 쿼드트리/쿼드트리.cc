#include <bits/stdc++.h>
using namespace std;

int n;
char board[65][65];

string quard(int x, int y, int size) {
    if(size == 1) {
        return string(1, board[x][y]);
    }
    char c = board[x][y];
    bool flag = 0;
    string result = "";
    for(int i=x; i <x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(c != board[i][j]) {
                result += '(';
                result += quard(x, y, size/2); // 왼쪽 위
                result += quard(x, y + size/2, size/2); // 오른쪽 위
                result += quard(x + size/2, y, size/2); // 왼쪽 아래
                result += quard(x + size/2, y + size/2, size/2); // 오른쪽 아래
                result += ')';
                return result;
            }
        }
    }
    return string(1, board[x][y]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            board[i][j] = str[j];
        }
    }
    cout << quard(0, 0, n) << "\n";
    return 0;
}