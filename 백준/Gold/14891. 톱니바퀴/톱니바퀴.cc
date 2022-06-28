#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// rotCheck 배열을 두어 특정 톱니바퀴를 움직일 때,
// 그 톱니바퀴의 왼쪽과 오른쪽 톱니바퀴를 각각 쭉 확인하여 
// 왼쪽 톱니바퀴의 2번 인덱스와 오른쪽 6번바퀴의 6번 인덱스가 같은지 확인하고,
// 다르다면 회전할 수 있으므로 회전 방향을 기록했다.

// 톱니바퀴의 시계방향, 반시계 방향 회전 처리는 다음과 같이 처리한다.
// 시계방향처리 : 10101111 => 11010111 : 벡터의 맨뒤의 원소를 앞에다 넣어준다.
// 반시계방향처리 : 10101111 => 01011111 : 벡터의 맨앞의 원소를 뒤에다 넣어준다.

vector<string> gear(5); // 각 톱니바퀴에 대한 톱니 정보
int rotCheck[5]; // 회전방향을 기록하는 배열 
// 1 : 시계방향으로 회전,  -1 : 반시계 방향으로 회전
int k, answer;

// 점수를 계산하는 함수
void getScore() {
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == '1') {
			answer += (1 << i - 1); 
		}
	}
}

// 톱니바퀴를 회전하는 함수
void rotate() {
	for (int i = 1; i <= 4; i++) {
		// 시계 방향으로 회전
		if (rotCheck[i] == 1) {
			string tmp = "";  // 한 톱니바퀴에 대해 새롭게 회전되는 정보를 저장하는 임시변수
			tmp = gear[i].back(); // 맨 끝 인덱스의 톱니를   
			gear[i].insert(0, tmp);  // 0번 인덱스로 이동
			gear[i].pop_back(); // => 맨 끝 인덱스는 7번 => 6번 => 5번 => ... => 0번으로 바뀐다.
		}

		// 반시계 방향으로 회전
		if (rotCheck[i] == -1) {
			char tmp = gear[i].front(); // 맨앞 원소를 추출해서
			gear[i].push_back(tmp); // 맨뒤에 넣고
			gear[i].erase(gear[i].begin()); // 추출해낸 기존의 맨앞 원소를 삭제
		}
	}
}
// 톱니바퀴가 어느 방향으로 움직이는지 확인하는 함수

void check(int target, int cmd) {
	rotCheck[target] = cmd;

	// 타겟 톱니바퀴로부터 왼쪽 톱니바퀴들에 대해 차례대로 확인
	for (int left = target - 1; left >= 1; left--) {
		int right = left + 1;
		// Case1. 왼쪽 톱니바퀴의 2번 인덱스 == 오른쪽 톱니바퀴의 6번 인덱스라면 움직이지 않음
		if (gear[left][2] == gear[right][6])
			break;
		// Case2. 왼쪽 톱니바퀴의 2번 인덱스 != 오른쪽 톱니바퀴의 6번 인덱스라면 반대 방향으로 움직임
		if (gear[left][2] != gear[right][6])
			rotCheck[left] = rotCheck[right] * -1;
	}

	// 타켓 톱니바퀴로부터 오른쪽 톱니바퀴들에 대해 차례대로 확인
	for (int right = target + 1; right <= 4; right++) {
		int left = right - 1;
		// Case1. 왼쪽 톱니바퀴의 2번 인덱스 == 오른쪽 톱니바퀴의 6번 인덱스면 움직이지 않음
		if (gear[left][2] == gear[right][6])
			break;
		// Case2
		if (gear[left][2] != gear[right][6]) {
			rotCheck[right] = rotCheck[left] * -1; // 반대 방향으로 회전
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 4; i++) {
		cin >> gear[i];
	}

	cin >> k; // k번 회전
	while (k--) { // 각 회전에 대해 실행
		int target, cmd; // target : 회전하려는 톱니바퀴, cmd : 회전방향 (방향인 1인 경우는 시계방향, -1인 경우는 반시계 방향)
		cin >> target >> cmd;
		check(target, cmd); 
		rotate();
		memset(rotCheck, 0, sizeof(rotCheck)); // 한 회전에 대한 처리가 다 끝났으면 rotCheck 배열 인덱스를 0으로 초기화
	}

	getScore(); 
	cout << answer;
}