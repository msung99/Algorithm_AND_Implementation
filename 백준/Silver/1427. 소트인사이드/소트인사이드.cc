#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	vector<int> arr;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr.push_back(str[i] - '0');
	}

	sort(arr.rbegin(), arr.rend());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
}