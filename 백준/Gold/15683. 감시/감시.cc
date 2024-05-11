#include <bits/stdc++.h>
using namespace std;

int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int,int>> cctv;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void search(int x, int y, int dir) {
    dir %= 4;
    while(true) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >= m) {
            break;
        }
        if(board2[x][y] == 6) {
            break;
        }
        
        if(board2[x][y] == 0) {
            board2[x][y] = 7;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6) {
                cctv.push_back({i, j});
            } 
        }
    }

    int mn = 999999999;
    for(int tmp=0; tmp < (1<<(2*cctv.size())); tmp++) {
        int brute = tmp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        for(int i=0; i<cctv.size(); i++) {
            int cctvX = cctv[i].first;
            int cctvY = cctv[i].second;
            int dir = brute % 4;
            brute = brute / 4;
            if(board1[cctvX][cctvY] == 1) {
                search(cctvX, cctvY, dir);
            }

            if(board1[cctvX][cctvY] == 2) {
                search(cctvX, cctvY, dir);
                search(cctvX, cctvY, dir+2);
            }

            if(board1[cctvX][cctvY] == 3) {
                search(cctvX, cctvY, dir);
                search(cctvX, cctvY, dir+3);
            }

            if(board1[cctvX][cctvY] == 4) {
                search(cctvX, cctvY, dir);
                search(cctvX, cctvY, dir+2);
                search(cctvX, cctvY, dir+3);
            }

            if(board1[cctvX][cctvY] == 5) {
                search(cctvX, cctvY, dir);
                search(cctvX, cctvY, dir+1);
                search(cctvX, cctvY, dir+2);
                search(cctvX, cctvY, dir+3);
            }
        }
        int cur = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board2[i][j] == 0) {
                    cur++;
                }
            }
        }
        mn = min(cur, mn);
    }

    cout << mn;

    return 0;
}