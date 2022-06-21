#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int board1[21][21];  // 원본 보드판 
int board2[21][21];  // 이동및 회전에 따라서 변경된 보드판


// board2 를 90도 회전시키는 함수
void rotation() {
	int tmp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}
}

/*
void move(int dir) {
	while (dir--) rotation();
	for (int i = 0; i < n; i++) {
		int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
		int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
				tilted[idx++] *= 2;
			else // 다른 값을 갖는 블록이 충돌
				tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]에 tilted를 덮어씀
	}
}
*/

void move(int dir) {
	while (dir--)
		rotation();
	for (int i = 0; i < n; i++) {
		int tmpArr[21] = {};   // 한 행 (행 i) 에 대해서 왼쪽으로 기울인 결과를 저장하는 임시배열 
		int idx = 0; // tmpArr 배열에서 어디에 저장해야할지를 가리키는 인덱스 변수
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0)  // 0 은 저장할 필요없으므로 skip
				continue;
			
			if (tmpArr[idx] == 0)  // 삽입할 위치가 빈 경우
				tmpArr[idx] = board2[i][j];  // 삽입
			
			else if (tmpArr[idx] == board2[i][j]) {  // 같은 값을 가진은 블록이 충돌할 경우
				tmpArr[idx] *= 2;  // 두 블록을 병합시킴
				idx++;
			}

			else {  // 다른 값을 가지는 두 블록이 충돌하는 경우
				idx++;
				tmpArr[idx] = board2[i][j];
			}
		}
		for (int j = 0; j < n; j++) {    // 해당 한 행을 카피
			board2[i][j] = tmpArr[j];
		}
	}
}

/*
// 한 행의 모든 블록을 좌측으로 이동시키기
void make_and_insert(vector<int>& list) {
	int index = 0;
	while (index != list.size() - 1)
	{
		if (list[index] == list[index + 1]) {
			list[index] = 2 * list[index];
			list.erase(list.begin() + index + 1);
		}
		else
			index++;
	}
}

// 좌측으로 블록을 모두 이동시켜서 병합시킴 
void move(int dir) {
	while (dir--)  
		rotation();   // board2 를 90도 회전시킴

	for (int i = 0; i < n; i++) {
		vector<int> list;  // 각 행의 리스트
		for (int j = 0; j < n; j++) {
			board2[i][j] = board1[i][j]; // board2 에 원소를 하나씩 카피하면서
			if (board2[i][j] != 0)     // 해당 원소가 0아 아닌 경우 list 에 추가
				list.push_back(board2[i][j]);
		}
		make_and_insert(list);  // 한 행을 기울이기

		for (int idx = 0; idx < n; idx++) {   // 기울여진 해당 행을 board2의 i행에다 카피 
			if (idx < list.size())
				board2[i][idx] = list[idx];
			else
				board2[i][idx] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board2[i][j] << ' ';
		}
		cout << "하이" << endl;
	}
	cout << "=====" << endl;
}
*/

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
		}
	}

	int mx = 0;  // 가장 큰 블록의 최댓값 (정답)

	// 5번 회진시키는 각각의 회전 방향을 결정
	for (int tmp = 0; tmp < 1024; tmp++) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				board2[i][j] = board1[i][j];  // board2 에다 board1 의 내용을 카피해줌
			int brute = tmp;
			// 5개 방향으로 회전
			for (int i = 0; i < 5; i++) {   
				int dir = brute % 4;
				brute = brute / 4;
				move(dir);
			}
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < n; j++) 
					mx = max(mx, board2[i][j]);
	}
	cout << mx;
}