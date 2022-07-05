#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
	return a.first >  b.first;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	// pair : {cnt, num} => {숫자 등장횟수, 숫자} 를 저장
	// stable_sort() 를 활용할 것이므로, pair 쌍에서 first 에 등장횟수가 위치하도록 한다.
	// 즉, 숫자 등장횟수를 먼저 비교하고 같은 경우에 두번째 원소 (second) 인 숫자를 비교하도록 하기 떄문.
	vector<pair<int, int>> arr; // pair : {숫자 등장횟수, 숫자} 
	
	// 입력받은 숫자를 arr 에서 탐색하고, 존재하는 경우 해당 숫자에 대한 등장횟수를 카운팅하기
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		bool check = false;
		for (pair<int,int>& element : arr) {
			if (element.second == data) { // 입력받은 숫자가 arr 에 존재한다면
				element.first++; // 해당 숫자의 등장횟수 1증가
				check = true;
				break; // 숫자를 찾고 카운팅했다면 더 이상 for문을 돌려서 숫자를 찾을 필요가 없으니 break
			}
		}
		// 해당 숫자가 arr 에 존재하지 않는 경우
		if (!check) {
			arr.push_back({1, data});  // 새롭게 pair 쌍을 arr 에 만들기. 이때 등장횟수는 이번이 처음 등장한 것이니까 1로 초기화.
		}
	}

	// stable_sort() : pair 의 가장 앞 원소(first) 를 먼저 비교하고, 값이 같다면(우선순위가 같다면)  그 다음 원소를 비교하는 방식
	stable_sort(arr.begin(), arr.end(), compare);
	for(int i=0; i < arr.size(); i++){
		while (arr[i].first--)
			cout << arr[i].second << ' ';
	}
}