#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int note[42][42];
int paper[12][12];

// 1. note 의 (x,y) 좌표를 시작점으로 할때 이 note 공간을 모눈종이가 채울 수 있는지 판단함
// 2. 채울 수 있다면 채우고 true 를 리턴.
bool pastable(int x, int y) {
    // 1. note 의 (x,y) 좌표를 시작점으로 할때 이 note 공간을 모눈종이가 채울 수 있는지 판단함
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(note[x+i][y+j] == 1 && paper[i][j] == 1) {
                return false;
            }
        }
    }    
    // 2. 채울 수 있다면 채우고 true 를 리턴.
    for(int i=0; i < r; i++) {
        for(int j=0; j < c; j++) {
            if(paper[i][j] == 1) {
                note[x+i][y+j] = 1;
            }
        }
    }
    return true;
}

// 모눈종이를 90도 회전시키는 함수
void rotate_paper() {
    int tmp[12][12];

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = paper[i][j];
        }
    }

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            paper[i][j] = tmp[r-1-j][i];
        }
    }

    swap(r, c);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    while(k--) {
        cin >> r >> c;

        // 모눈종이 정보를 입력받는다.
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> paper[i][j];
            }
        }

        // 최대 4번 회전하면서 빈 공간 채우기를 시도한다. 4번 이상이 되면 현재 모눈종이를 버린다.
        for(int rot=0; rot<4; rot++) {
            bool is_paste = false;
            for(int i=0; i <= n-r; i++) {
                if(is_paste) {
                    break;
                }
                for(int j=0; j <= m-c; j++) {
                    if(pastable(i, j)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) {
                break;
            }
            rotate_paper();
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(note[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}