#include <bits/stdc++.h>
using namespace std;

int n;
int s[10];
int w[10];
int mx;
int cnt;

// k번째 계란을 손에 쥐고 꺠뜨리기를 시도
void func(int k) {
  if(k == n) {
    mx = max(mx, cnt);
    return;
  }

  // 현재 손에 쥔 계란이 이미 깨졌거나 or 다른 모든 계란이 깨져있다면
  if(s[k] <= 0 || cnt == n-1) {
    func(k+1);
    return;
  }

  // t번째 계란에 대해 내려찍기를 시도힘
  for(int t=0; t<n; t++) {
    if(t == k || s[t] <= 0) {
      continue;
    }

    // 내려찍고 두 계란의 내구도를 감량시킴
    s[k] -= w[t];
    s[t] -= w[k];

    // 내려찍은 결과 내구도가 0보다 작다면, 즉 게란이 깨졌다면
    if(s[k] <= 0) {
      cnt++; // 꺠진 계란 갯수 카운팅
    }
    if(s[t] <= 0) {
      cnt++;
    }

    func(k+1);

    if(s[k] <= 0) {
      cnt--; // 꺠진 계란 갯수 복구시킴
    }
    if(s[t] <= 0) {
      cnt--;
    }

    // 내구도 복구 시킴
    s[k] += w[t];
    s[t] += w[k];
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> s[i] >> w[i];
  }

  func(0);

  cout << mx;

  return 0;
}