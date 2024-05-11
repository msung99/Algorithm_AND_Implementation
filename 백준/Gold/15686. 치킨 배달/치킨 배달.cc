#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int data;
            cin >> data;
            if(data == 1) {
                house.push_back({i, j});
            }
            if(data == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    // chicken.size() 개 중에서 m개를 선택하기 위한 셋팅
    int mn = 999999999;

    do {
        int dist = 0;
        for(auto h : house) {
            int tmp = 999999999;
            for(int i=0; i<chicken.size(); i++) {
                if(brute[i] == 1) {
                    tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));                    
                }
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while(next_permutation(brute.begin(), brute.end()));

    cout << mn;

    return 0;
}