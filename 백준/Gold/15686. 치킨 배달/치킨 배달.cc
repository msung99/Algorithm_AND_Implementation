#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[53][53];
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
      cin >> board[i][j];

      if(board[i][j] == 1) {
        house.push_back({i, j});
      }

      if(board[i][j] == 2) {
        chicken.push_back({i, j});
      }
    }
  }

  vector<int> brute(chicken.size(), 1); // 조합(combination)에 사용할 리스트 생성
  fill(brute.begin(), brute.begin() + chicken.size() - m, 0);

  int ans = 999999999; // 정답 저장 변수

  do {
    int dist = 0; // 도시의 치킨 거리를 저장할 변수
    for(auto h : house) { // 각 집에 대하여
      int tmp = 999999999;
      for(int i=0; i<chicken.size(); i++) {
        if(brute[i] == 0) {
          continue;
        }        
        // 2개의 치킨 집을 순열 방식으로 추출하고, 현재 집과 추출된 치킨 집에 대한 거릿값 계산
        tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
      }
      dist += tmp;
    }
    // 한 집에대한 순환이 끝나면 현재 집에 대해 계산된 거리값과 비교하여 최솟값을 구함
    ans = min(ans, dist);
  } while(next_permutation(brute.begin(), brute.end()));

  cout << ans;
  
  return 0;
}