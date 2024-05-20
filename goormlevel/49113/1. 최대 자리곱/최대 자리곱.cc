#include <bits/stdc++.h>
using namespace std;

string convert_input(string input, int i) {
	int temp = stoi(input.substr(0, i+1)) -1;
	if(temp == 0) {
		return string(input.size() - (i+1), '9');
	} else {
		return to_string(temp) + string(input.size() - (i+1), '9');
	}
}

int calc_mul(string input) {
	int res = 1;
	for(int i=0; i<input.size(); i++) {
		res *= input[i] - '0';
	}
	return res;
}

int find_biggest_mul(string input) {
	int biggest_mul = calc_mul(input);
	
	for(int i=0; i<input.size()-1; i++) {
		string temp = convert_input(input, i);
		int temp_mul = calc_mul(temp);
		
		if(temp_mul > biggest_mul) {
			biggest_mul = temp_mul;
		}
	}
	return biggest_mul;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string input;
	cin >> input;
	
	cout << find_biggest_mul(input);
	
	return 0;
}