#include <bits/stdc++.h>
using namespace std;

int n;
bool isused1[30];
bool isused2[30];
bool isused3[30];
int cnt;

// k-1번쨰까지 퀸을 배치했다면, K번째 퀸도 배치할 수 있다.
// K번쨰 퀸을 배치하는 방법 : k-1 번쨰까지 배치한 퀸들과 동일한 y축, (x+y)축, (x-y)축에 위치해선 안된다.
void func(int k) {
  if(k == n) { // k번째 퀸까지 배치하는데 모두 성공했다면 
    cnt++; // 배치를 카운팅
    return;
  }

  for(int i=0; i<n; i++) {
    // 퀸을 배치하려는데, 이미 동일한 축 / (x+y)축 / (x-y)축에 배치된 퀸이 존재한다면
    if(isused1[i] || isused2[k+i] || isused3[k-i+n-1]) {
      continue; // 배치 못함
    }

    // k번째 퀸을 배치한다.
    // 배치할때 x축, (x+y)축, (x-y)축에 배치 여부를 표시한다.
    isused1[i] = true;
    isused2[k+i] = true;
    isused3[k-i+n-1] = true;
    
    func(k+1);

    isused1[i] = false;
    isused2[k+i] = false;
    isused3[k-i+n-1] = false;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  func(0);

  cout << cnt;

  return 0;
}