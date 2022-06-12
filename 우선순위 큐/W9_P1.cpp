#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> list;
		int n;
		cin >> n;
		while (n--)
		{
			int data;
			cin >> data;
			list.push_back(data);
		}
		sort(list.begin(), list.end());
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << ' ';
		}
		cout << endl;
	}
}