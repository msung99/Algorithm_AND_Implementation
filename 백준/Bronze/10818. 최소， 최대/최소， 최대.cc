#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	cout << *min_element(arr.begin(), arr.end()) << ' ' << *max_element(arr.begin(), arr.end());
}