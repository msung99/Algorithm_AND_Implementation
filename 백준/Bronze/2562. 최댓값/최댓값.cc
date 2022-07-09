#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int max = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		int data;
		cin >> data;
		if (data > max) {
			max = data;
			idx = i + 1;
		}
	}
	cout << max << '\n' << idx;
}