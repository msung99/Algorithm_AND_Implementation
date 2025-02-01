#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[52][52];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];

            if(board[i][j] == 1) {
                house.push_back({i, j});
            }

            if(board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size()-m, 0);

    int ans = 1999999999;

    do {
        int cur = 0;

        for(auto h : house) {
            int houseMin = 1999999999;
            
            for(int i=0; i<brute.size(); i++) {
                if(brute[i] == 1) {
                    houseMin = min(houseMin, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
                }
            }
            cur += houseMin;
        }
        ans = min(ans, cur);
    } while(next_permutation(brute.begin(), brute.end()));

    cout << ans;

    return 0;
}