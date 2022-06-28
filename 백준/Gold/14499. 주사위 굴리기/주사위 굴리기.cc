#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; // 지도의 세로크기, 가로크기
int x, y; // 주사위를 놓은 곳의 좌표 (x,y)
int k; // 명령의 개수

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int map[20][20];
int dice[7] = { 0 };
vector<int> cmd;  // 입력으로 주어진 이동하는 명령을 저장하는 벡터

// 입력값 받기
void input() {
	cin >> n >> m >> x >> y >> k;

	// 지도 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j]; 
		}
	}
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		a = a - 1;
		cmd.push_back(a); // 입력주어진 이동하는 명령을 저장
	}
}

// 주사위를 지도에서 굴리면서, 지도에 등장하는 좌표
void RollTheDice(int d) // d : 이동하는 명령 => 1:동쪽, 2:서쪽, 3:북쪽, 4:남쪽
{
	int d1, d2, d3, d4, d5, d6;
	d1 = dice[1];
	d2 = dice[2];
	d3 = dice[3];
	d4 = dice[4];
	d5 = dice[5];
	d6 = dice[6];

	// 주사위를 굴려서 이동한 칸에 쓰여있는 수가 0이면, 주사위의 바닥면에 쓰여있는 수가 해당 지도의 칸에 복사된다.
	if (d == 0)  // 동쪽으로 이동하는 경우
	{
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}

	// 0이 아닌 경우는, 칸에 쓰여있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여있는 수는 0이 된다.
	else if (d == 1) // 서쪽으로 이동하는 경우
	{
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}

	else if (d == 2) // 북쪽으로 이동하는 경우
	{
		dice[1] = d5;
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
	}

	else if (d == 3) // 남쪽으로 이동하는 경우
	{
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
	}
}

void solution()
{
	int x1 = x;
	int y1 = y;

	for (int i = 0; i < cmd.size(); i++)
	{
		int nx = x1 + dx[cmd.at(i)];
		int ny = y1 + dy[cmd.at(i)];
		int d = cmd.at(i);

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		RollTheDice(d);
		if (map[nx][ny] == 0)
			map[nx][ny] = dice[6];

		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << endl;
		
		x1 = nx;
		y1 = ny;
	}
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	solve();
	return 0;
}