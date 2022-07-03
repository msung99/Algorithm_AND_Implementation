#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 사용자 정의 정렬기준 (첫번째 원소를 기준으로 오름차순)
// => 즉, 순서쌍의 "첫번쨰 원소" 가 작다면 앞쪽에 오도록 한다 (오름차순)
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


bool compare2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}


int main(void)
{
	int n;
	cin >> n;
	pair<int, int> tmp;
	vector<pair<int, int>> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp.first >> tmp.second;
		arr.push_back(tmp);
	}

	stable_sort(arr.begin(), arr.end(), compare);  // stable sort 정렬방법 진행시 정렬기준을 compare 함수로 설정한다. 
	stable_sort(arr.begin(), arr.end(), compare2);
	

	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}