#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int m = 0;
	int i = 0;
	cin >> n;
	vector<int> card(n, 0);

	for (int i = 0; i < n; i++)
		cin >> card[i];

	sort(card.begin(), card.end());

	cin >> m;
	sort(card.begin(), card.end());
	int num = 0;

	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << ' ';
	}
}