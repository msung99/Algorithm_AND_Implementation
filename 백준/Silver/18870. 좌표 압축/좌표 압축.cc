#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000005];
vector<int> uni; // unique
// vector<int> tmp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
		//tmp.push_back(x[i]);
	}

	sort(uni.begin(), uni.end());
	//sort(tmp.begin(), tmp.end());

	// tmp 의 중복원소를 제거한 결과물이 uni 에 담긴다.
	// cf) 만일 uni 배열을 활용하지않고 tmp 에서 원소를 제거하는 작업이라면 O(n^2) 이라는 시간이 걸린다!
	
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
//	for (int i = 0; i < n; i++) {
//		if (i == 0 || tmp[i - 1] != tmp[i]) // 여러번 등장하는 같은 수 중에서 가장 앞에있는 수 하나만 uni 에 push된다.
//			uni.push_back(tmp[i]);
//	}

	// lower_bound 내장함수를 활용
	// => 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾는함수
	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' '; // iterator(이터레이터) 를 lower_bound 를 이용해 찾아서
	}                                                                       // uni.begin() 를 빼주면 그것이 바로 x[i] 가 등장하는 인덱스가 된다.
}                                                             // 쉽게말해, 이터레이터가 uni[4]를 가리키고있다면 위 코드가 4를 출력하는 것이다!

