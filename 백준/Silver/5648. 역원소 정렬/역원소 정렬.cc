#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// n개의 숫자를 string 으로 입력받고 reverse 함수로 뒤집는다.
// 그리고 long long 타입의 벡터에 push_back 한후,
// sort() 를 활용해 오름차순 정렬하면 된다.

// * 문자에서 숫자로 변환하기
// stoi : string to int
// stol : string to long
// stoll : string to long long 
// stof : string to float
// stod : string to double

vector<string> origin;
vector<long long> list;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string data;

	// 1. n개의 숫자를 문자열로 입력받고 뒤집기
	for (int i = 0; i < n; i++) {
		cin >> data;
		reverse(data.begin(), data.end());
		origin.push_back(data);
 	}

	// 2. 입력받은 문자열 타입의 데이터들을 
	// long long 타입으로 변환후, long long 타입의 벡터에 push_back
	for (int i = 0; i < n; i++) {
		list.push_back(stoll(origin.front()));
		origin.erase(origin.begin());
	}

	// 3. 정렬후 출력 
	sort(list.begin(), list.end());
	for (int i = 0; i < n; i++) {
		cout << list[i] << '\n';
	}
}