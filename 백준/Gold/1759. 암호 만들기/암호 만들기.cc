#include <bits/stdc++.h>
using namespace std;

int l, c; // c개중에 l개를 택함
char arr[20];
char input[20];
bool isused[20];

bool isAeiou(char c) {
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  }
  return false;
}

void func(int k, int start) {
  if(k == l) {
    int num1 = 0;
    int num2 = 0;
    for(int i=0; i<l; i++) {
      if(isAeiou(arr[i])) {
        num1++;
      } else {
        num2++;
      }
    }

    if(num1 >=1 && num2 >= 2) {
      for(int i=0; i<l; i++) {
        cout << arr[i];
      }
      cout << "\n";
      return;
    }
  }

  for(int i=start; i<c; i++) {
    if(!isused[i]) {
      arr[k] = input[i];
      isused[i] = true;
      func(k+1, i+1); // 현재 input 배열의 i번째 숫자를 택했다면, 다음에 선택할 숫자는 i+1 번째 부터 시작한다.
      isused[i] = false;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> l >> c;

  for(int i=0; i<c; i++) {
    cin >> input[i];
  }
  sort(input, input + c);

  func(0, 0);

  return 0;
}