#include <iostream>
using namespace std;

int n;
int arr[1001];
int new_arr[3003];

bool check(int num) {
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			for (int k = 1; k <= 50; k++)
				if (arr[i] + arr[j] + arr[k] == num)
					return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 1000; i++) {
		arr[i] = arr[i - 1] + i; //  (1 부터 (i-1) 까지의 합 +  i)  ==  (1 부터 i 까지의 합) 
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << check(num) << '\n';
	}
}
