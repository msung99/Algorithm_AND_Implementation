#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	string te1, te2;
	cin >> testCase;
	int arr[26] = { 0, };
	int arr2[26] = { 0, };
	int count = 0;
	for (int i = 0; i < testCase; i++) {
		cin >> te1;
		cin>> te2;
		
		for (int i = 0; i < te1.size(); i++) {
			arr[te1[i] - 'a']++;
		}
		for (int i = 0; i < te2.size(); i++) {
			arr2[te2[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] > 0 && arr2[i] > 0) {
				if (arr[i] == arr2[i]) {
					count += arr[i];
				}
			}
		}
		if (count == te1.size()) {
			cout << "Possible" << "\n";
		}
		else {
			cout << "Impossible" << "\n";
		}

		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
			arr2[i] = 0;
		}
		count = 0;
	}
	
}