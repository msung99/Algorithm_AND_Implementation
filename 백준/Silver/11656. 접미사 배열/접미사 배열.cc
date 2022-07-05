#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
	return a < b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	vector<string> list;

	for (int i = 0; i < str.length(); i++) {
		string subStr = "";
		for (int j = i; j < str.length(); j++) {
			subStr += str[j];
		}
		list.push_back(subStr);
	}

	sort(list.begin(), list.end(), compare);
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << '\n';
	}
}