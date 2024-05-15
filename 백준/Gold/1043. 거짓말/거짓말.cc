#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> party;

// 현재 파티에서 진실을 아는 사람이 존재하는지 판단하는 함수
bool isMatch(vector<int> group, int person) {
  auto it = find(group.begin(), group.end(), person);
  if(it != group.end()) {
    return true;
  }
  return false;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  int t;
  cin >> t;

  queue<int> q;

  // 진실을 아는 사람을 큐에 넣는다.
  while(t--) {
    int data;
    cin >> data;
    q.push(data);
  }

  for(int i=0; i <m; i++) {
    vector<int> tmp;
    int a;
    cin >> a;

    // 한 파티 그룹 데이터 입력받음
    while(a--) {
      int p;
      cin >> p;
      tmp.push_back(p);
    }

    // 파티 그룹에 현재 파티를 추가
    party.push_back(tmp);
  }

  // 큐가 빌 때까지 BFS 를 수행
  while(!q.empty()) {
    int cur = q.front(); // 진실을 아는 사람을 큐에서 추출
    q.pop();

    // 모든 파티에 대해 순회
    for(int i=0; i<party.size(); i++) {
      // 만약 i번째 파티(party[i])에서 진실을 아는 사람(cur) 이 존재한다면
      if(isMatch(party[i], cur)) {
        // 해당 파티의 모든 사람들은 진실을 아는 사람들이 된다. 즉, 진실을 아는 것으로 전염된다. 따라서 큐에 push 
        for(auto person : party[i]) {
          q.push(person);
        }
        party.erase(party.begin() + i); // 해당 파티를 삭제한다. 
      }
    }
  }

  cout << party.size(); // 현재 남아있는 파티의 수가 곧 거짓말을 할 수 있는 파티의 수이다.

  return 0;
}


