#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int M, N;
	vector<int> L;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	//이분탐색, 이진탐색
	int left = 1, right = *max_element(L.begin(), L.end());
	//left: 가장 작은 수, right: 가장 큰 수
	int snack = 0;

    // m명의 조카에게 길이가 mid 인 과자를 나눠줄떄 몇명(count) 에게 나눠줄 수 있는지 구함
	while (left <= right) {
		int mid = (left + right) / 2; //중앙값
		int count = 0;
		for (int i = 0; i < N; i++) {
			count += L[i] / mid; //mid 과자 길이로 나눠줄수 있는 양
            // ex) mid = 8 일때
            // (1/8) + (2/8) + (3/8) + ... (8/8) + (9/8) + (10/8)
            // = 0+0+0+...+0+1+1+1 = 3
		}
		if (count >= M) { //과자 나눠줄수 있을 때
			left = mid + 1;
			snack = mid;
		}
		else if (count < M) { //과자 나눠줄수 없을 때
			right = mid - 1;
		}
	}
	cout << left-1 << "\n";

	return 0;
}