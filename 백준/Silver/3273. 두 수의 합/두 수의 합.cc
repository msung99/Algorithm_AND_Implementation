// 투 포인터 활용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int len,num,target;
  vector<int> v1; // 벡터

  cin >> len;
  for(int i=0; i<len; i++){ // 벡터에 원소 할당
    cin >> num;
    v1.push_back(num);
  }

  sort(v1.begin(), v1.end()); // 오름차순 정렬

  cin >> target; // 두 수의 합 타깃. 두 수를 더했을 때 값이 target이 되면 정답
  int left = 0, right = len-1, count = 0; // left, right : 투 포인터

  // 투 포인터 활용
  while(right > left){
    int sum = v1[left] + v1[right];
    if(sum == target){ // 쌍을 찾은 경우(정답인 경우)
      count++; // 쌍의 개수 증가
      left++; // 투포인터가 각각로 한칸씩 넘어감 
      right--;
    }
    else if(sum < target) // target보다 작으면 sum 값을 더 키워야하므로 left 포인터 증가
      left++; 
    else // target 보다 크면 sum 값을 낮춰야하므로 right 포인터 감소
      right--;
  }
  cout << count;
}
