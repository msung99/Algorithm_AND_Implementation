#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

map <int, int> order; //index 저장

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return order[a.first] < order[b.first]; //기존의 순서 지키기

	return a.second > b.second;
}

int main()
{
	//freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	map<int, int> m;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m[num]++;

		if (order[num] == 0)
			order[num] = i+1;
	}
	
	vector<pair<int, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), cmp);

	for (auto x : vec)
	{
		for (int i = 0; i < x.second; i++)
		{
			cout << x.first << " ";
		}
	}

	return 0;
}