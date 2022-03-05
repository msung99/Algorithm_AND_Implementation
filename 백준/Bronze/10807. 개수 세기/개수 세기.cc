#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n,num;
  cin >> n;
  vector<int> v1;

  for(int i=0; i<n; i++){
    cin >> num;
    v1.push_back(num);
  }

  int count = 0, target;
  cin >> target;

  for(int i=0; i< v1.size(); i++){
    if(v1[i] == target) count++;
  }
  cout << count;
}