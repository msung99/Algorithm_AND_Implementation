#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, coin;
	int total = 0;
	cin >> coin >> n;
	for (int i = 0; i < n; i++) {
		int data1, data2;
		cin >> data1 >> data2;
		int cur = data1 * data2; 
		total += cur;
	}
	if (total == coin)
		cout << "Yes";
	else
		cout << "No";
}