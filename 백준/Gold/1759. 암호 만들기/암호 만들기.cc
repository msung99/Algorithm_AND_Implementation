#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20];
char num[20];

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
      } else{
        num2++;
      }
    }

    if(num1 >= 1 && num2 >= 2) {
      for(int i=0; i<l; i++) {
        cout << arr[i];
      }
      cout << "\n";
    }
    return;
  }

  for(int i=start; i<c; i++) {
    arr[k] = num[i];
    func(k+1, i+1);
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> l >> c;

  for(int i=0; i<c; i++) {
    cin >> num[i];
  }
  sort(num, num + c);

  func(0, 0);

  return 0;
}