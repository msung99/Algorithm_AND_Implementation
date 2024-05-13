#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10];
int tmp[10][10];
vector<pair<int,int>> wall;
vector<pair<int,int>> virus;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void init(vector<pair<int,int>> curWall) {
  for(int i=0; i<n; i++) {
    // fill(vistied[i], vistied[i] + m, false); // 방문 배열 초기화
    for(int j=0; j<m; j++) {
      tmp[i][j] = board[i][j]; // board 배열을 tmp 배열에 카피
    }
  }

  // 벽 3개 셋팅
  for(int i=0; i<curWall.size(); i++) {
    int x = curWall[i].first;
    int y = curWall[i].second;
    tmp[x][y] = 1;
  }
}

// board 가 아닌, tmp 배열에 대해 BFS 를 수행
int bfs(vector<pair<int,int>> curWall) {
  init(curWall);
  queue<pair<int,int>> q;
  for(int i=0; i<virus.size(); i++) {
    q.push(virus[i]);
  }

  while(!q.empty()) {
    auto cur = q.front();
    int x = cur.first;
    int y = cur.second;
    q.pop();
    tmp[x][y] = 1;

    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }

      if(tmp[nx][ny] == 1 || tmp[nx][ny] == 2) {
        continue;
      }

      tmp[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  int cnt = 0;  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tmp[i][j] == 0) {
        cnt++;
      }
    }
  }
  return cnt;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board[i][j];
      if(board[i][j] == 0) {
        wall.push_back({i, j});
      }
      if(board[i][j] == 2) {
        virus.push_back({i, j});
      }
    }
  }

  vector<int> brute(wall.size(), 1);
  fill(brute.begin(), brute.end() - 3, 0); // 빈 칸들 중에 3개를 조합으로 선택
  int mx = 0;

  do {
    vector<pair<int,int>> curWall;
    // 3개의 빈칸을 벽으로 선택
    for(int i=0; i<brute.size(); i++) {
      if(brute[i] == 1) {
        curWall.push_back({wall[i].first, wall[i].second});
      }
    }
    int cur = bfs(curWall);
    mx = max(mx, cur);
  } while(next_permutation(brute.begin(), brute.end()));

  cout << mx;

  return 0;
}