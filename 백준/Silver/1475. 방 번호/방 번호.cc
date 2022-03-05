#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  int arr[10] ={0,};
  int a;
  int count = 0;

  cin >> n;
  
  while(n > 0){
    arr[n%10]++;
    n = n / 10;
  }

  int num = 0;
  for(int i=0; i<10; i++){
    if(i != 6 && i != 9) 
      num = max(num,arr[i]);
  }

  num = max(num, (arr[6]+arr[9]+1) /2 );
  
  cout << num;
}