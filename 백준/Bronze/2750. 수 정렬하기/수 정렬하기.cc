#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> list;
	int n;
	cin >> n;
	int data;
	while (n--){
		cin >> data;
		list.push_back(data);
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << '\n';
	}
}