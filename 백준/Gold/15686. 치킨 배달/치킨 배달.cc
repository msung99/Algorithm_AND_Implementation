#include <bits/stdc++.h>
using namespace std;

int n, m;
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

  int mn = 1999999999;
  do {
    int cur = 0;
    for(auto h : house) { // 각 집에대해 현재 부여된 m개의 치킨집중에 적절히 선택하여 최소 치킨거리 값을 계산 
      int houseMin = 199999999;

      for(int i=0; i<brute.size(); i++) {
        if(brute[i] == 1) {
          houseMin = min(houseMin, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));          
        }
      }

      cur += houseMin;
    }

    mn = min(cur, mn);

  } while(next_permutation(brute.begin(), brute.end()));

  cout << mn;

  return 0;
}