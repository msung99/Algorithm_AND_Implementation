#include <bits/stdc++.h>
using namespace std;

int counter[10];
int num[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int data;
		cin >> data;
		counter[i] = data;
	}
	
	for(int i=0; i<n; i++) {
		int data;
		cin >> data;
		num[i] = data;
	}
	
	int k;
	cin >> k;
	while(k--) {
		int idx = n-1;
		bool isOverflow = true;
		
		while(isOverflow) {
			num[idx]++;
			if(num[idx] <= counter[idx]) {
				isOverflow = false;
			} else {
				num[idx] = 0;
				idx--;
				if(idx < 0) {
					break;
				}
			}
		} 
	}
	
	for(int i=0; i<n; i++) {
		cout << num[i];
	}
	
	return 0;
}