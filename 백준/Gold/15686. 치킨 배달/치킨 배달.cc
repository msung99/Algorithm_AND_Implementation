#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// - 각 케이스마다 존재하는 치킨집 중에 폐업되는 치킨집 2의 상태를 0으로 바꾼다.
// - 잠시 생각해보면, 치킨집이 늘어나면 늘어날수록 치킨거리가 당연히 줄어든다. 따라서 바로 M개를 고르는 경우만 생각하면 된다. 
// ( 치킨집을 1개, 2개, 3개, .. M-1 개 고르는 경우는 고려하지 말것! )

int board[51][51]; // 원본 도시
 // xxxxx 각 케이스마다 폐업되는 치킨집 상태가 최신화된 도시
vector<pair<int, int>> chicken; // 치킨집의 좌표를 저장하는 벡터
vector<pair<int, int>> house;
int n, m;

// 치킨집 중에 m 개의 치킨집을 폐업시키는 조합을 생성하는 함수
void chicken_close() {
	vector<int> brute(chicken.size(), 1); // chicken 벡터의 사이즈만큼 1로 채움
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 1로 채운 brute 의 인덱스 0 부터 인덱스 chichen.size() - m 를 0으로 바꿈 
	// => ex. 치킨집이 5개 ( = chicken.size()) 이고 m 이 3인 경우 brute 는 {0,0,1,1,1} 로 채워져서 치킨집 3개를 선택 할수 있도록 해준다.
	do {
		for (int i = 0; i < chicken.size(); i++) {
			if (brute[i] == 0)
				continue;
			/* ~~~ */
		}
		cout << '\n';
	} while (next_permutation(brute.begin(), brute.end()));
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({ i,j });
			if (board[i][j] == 2)
				chicken.push_back({ i,j });
		}
	} 

	vector<int> brute(chicken.size(), 1); // chicken 벡터의 사이즈만큼 1로 채움
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 1로 채운 brute 의 인덱스 0 부터 인덱스 chichen.size() - m 를 0으로 바꿈 
	// => ex. 치킨집이 5개 ( = chicken.size()) 이고 m 이 3인 경우 brute 는 {0,0,1,1,1} 로 채워져서 치킨집 3개를 선택 할수 있도록 해준다.
	int mn = 9999999;
	do {
		int dist = 0;
		for (auto h : house) {
			int tmp = 99999999;
			for (int i = 0; i < chicken.size(); i++) {
				if (brute[i] == 0)
					continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << mn;
}