#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 사용자 정의 정렬기준 (첫번째 원소를 기준으로 오름차순)
// => 즉, 순서쌍의 "첫번쨰 원소" 가 작다면 앞쪽에 오도록 한다 (오름차순)
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main(void)
{
	int n;
	cin >> n;
	pair<int, string> tmp;
	vector<pair<int, string>> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp.first >> tmp.second;
		arr.push_back(tmp);
	}

	stable_sort(arr.begin(), arr.end(), compare);  // stable sort 정렬방법 진행시 정렬기준을 compare 함수로 설정한다. 
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}