#include <bits/stdc++.h>
using namespace std;

int n, m;

int play() {
	unordered_set<int> dic;
	
	bool isSuccess = false;
	for(int i=1; i<=m; i++) {
		int data;
		cin >> data;
		dic.insert(data);
		
		if(dic.size() == n) {
			return i;
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	cout << play();
	
	return 0;
}