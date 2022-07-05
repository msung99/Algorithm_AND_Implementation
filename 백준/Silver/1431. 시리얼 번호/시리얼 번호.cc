#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
1. 크기비교
- A와 B의 길이가 다르면, 짧은 것이 먼저 온다.

2. 합 구하고비교
- 길이가 같은경우, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서
작은 합을 가지는 것이 먼저온다 (숫자인 것만 더한다)

3. 사전순 비교
- 숫자가 알파벳보다 사전순으로 작다.
=> string 클래스는 연산자 오버로딩으로도 정의가 되어있는데,
">", "<" 의 연산자로 사전식 배열 크기 비교를 할 수 있다. 
*/

bool comapre(const string& a, const string& b)
{
	// 1. 길이 비교
	if (a.size() != b.size())
		return a.size() < b.size();

	// 2. 자리수의 합을 비교 (숫자인 것만 합한다.)
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < a.size(); i++) {
		if ('0' <= a[i] && a[i] <= '9')
			sum1 += a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		if ('0' <= b[i] && b[i] <= '9')
			sum2 += b[i] - '0';
	}

	if (sum1 != sum2)
		return sum1 < sum2;

	// 3. 사전순 비교
	return a < b;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> list;
	int n;
	string data;
	cin >> n;
	while (n--) {
		cin >> data;
		list.push_back(data);
	}

	sort(list.begin(), list.end(), comapre);
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << '\n';
	}
}


