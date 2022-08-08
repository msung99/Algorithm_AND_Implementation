#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int arr[26] = {0,};
  string s;
  cin >> s;

  for(int i=0; i < s.length(); i++){
     arr[s[i] - 'a']++;
  }

  for(int i=0; i < 26; i++){
    cout << arr[i] << ' ';
  }
}