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
	int data;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> data;
		list.push_back(data);
	}
	sort(list.rbegin(), list.rend());
	for (int i = 0; i < n; i++) {
		cout << list[i] << '\n';
	}
}