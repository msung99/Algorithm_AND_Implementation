#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
	if (a.size() != b.size())
		return a.size() < b.size();

	return a < b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> list;
	int n;
	cin >> n;

	string data;
	for (int i = 0; i < n; i++) {
		cin >> data;
		// 중복되는 원소를 입력하는 일을 방지하기 위해 find() 활용
		// find 함수 : 해당 단어가 존재하지 않을 경우 vector.end() 를 리턴한다.
		if (find(list.begin(), list.end(), data) == list.end())
			list.push_back(data);
	}

	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << '\n';

	/*
	// unique : 벡터에서 연속된 중복되는 원소를 맨 뒤로 보내는 함수
	sort(list.begin(), list.end(), compare);
	unique(list.begin(), list.end()); 
	for (int i = 0; i < list.size(); i++) { // 중복된 원소를 제거했으므로, "i < n" 이 아닌, "i < list.size()" 로 조건을 작성하자.
		cout << list[i] << '\n';
	}
	*/
}