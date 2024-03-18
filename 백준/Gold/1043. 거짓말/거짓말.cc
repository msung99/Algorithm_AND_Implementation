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


/* #include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> party; // 파티의 정보

// 파티 안에 진실을 아는 사람이 포함되어있는지 판단
bool isMatch(vector<int> v,int t){
    auto it = find(v.begin(),v.end(),t);
    if(it != v.end()) return true;
    else return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0); 

    cin >> N >> M;

    int num;
    cin >> num;

    queue<int> truth;

    // 진실을 아는 사람을 큐에 넣는다.
    while(num--) {
        int val;
        cin >> val;
        truth.push(val);
    }

    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        vector<int> tmp;
        while(n--){
            int p;
            cin >> p;
            tmp.push_back(p);
        }
        party.push_back(tmp);
    }

    // 진실을 아는 사람이 큐에 없을때까지 반복
    while(!truth.empty()){
        // 한명씩 뺀다.
        int t = truth.front();
        truth.pop();

        // 모든 파티를 순회
        for(int i = 0; i < party.size(); i++){
            if(isMatch(party[i],t)){
                // 진실된 사람이 속한 파티
                for(auto it : party[i]) {
                  truth.push(it); // 모든 사람을 큐에 넣음
                }
                party.erase(party.begin()+i); // 그 파티를 삭제
                i--;
            }
        }
    }
    cout << party.size();
}
*/