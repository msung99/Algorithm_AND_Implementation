#include <iostream>
using namespace std;

bool visited1[40];
bool visited2[40];
bool visited3[40];

int cnt = 0; // n개의 퀸을 적절히 배치 가능한 경우의 수
int n;

void func(int cur)  // func(cur) 에서는 (cur, 0), (cur, 1), ..., (cur, n-1) 에 퀸을 둘 수 있는지 확인한다.
{                   // 둘 수 있는지는 visited1, visited2, visited3 를 확인하면 된다.
	// 만일 둘 수 있다면 visited1[i], visited2[cur+i], visited3[cur-i+n-1] 을 true 로 변경한 후 func(cur+1) 을 호출하면 된다.

	if (cur == n) { // func(n) 을 호출하면 퀸을 n개를 놓는데 성공했다는 의미이니 cnt를 1 증가시킴
		cnt++;
		return;
	}

	// x좌표는 cur인 상태에서 y좌표인 i 값을 0부터 n-1 까지 돌음. (즉 위에서 언급했듯이, (cur, 0), (cur, 1), ..., (cur, n-1) 에 퀸을 둘 수 있는지 확인)
	for (int i = 0; i < n; i++) 
	{
		// 여기서 cur이 x좌표값이고, i가 y 좌표값 이다.  (즉 cur은 행을, i는 열을 의미한다)

		// 1. visited1[i] : 같은 열에 퀸이 있는지를 저장. => y좌표가 일치하는지 확인
		// (x,y) 에 퀸이 있으면 visited[y] 를, 즉 visited[i] 를 true 로 만들면 된다.
		//  ex) (0,1) 과 (2,1) 이 y좌표가 1로 동일하므로 둘은 같은 열에 있는 퀸으로, 두 퀸은 서로 공격을 하게된다. (부적절한 배치)
		
		// 2. visited2[i + cur] : 좌측 하단과 우측 상단을 잇는 대각선에 퀸이 있는지를 저장 => x + y 값이 같으면 같은 대각선에 두 퀸이 위치해 있는것이다
		// i + cur 은 x + y 를 의미한다. (x,y) 에 퀸이 있으면 visited2[x+y]를, 다시말해 visited2[i+cur] 를 true 로 만들면 된다.
		// ex) (3,0) 과 (1,2) 은 x + y = 3 으로, 같은 대각선 상에 위치해있어서 두 퀸은 서로 공격하게 된다. (부적절한 배치)
		
		// 3. visited3[cur - i + n -1] : 좌측 상단과 우측 하단을 잇는 대각선에 퀸이 있는지를 저장 => x - y 값이 같으면 같은 대각선에 두 퀸이 위치해 있는것
		// (x,y) 에 퀸이 있으면 visited3[x - y + n - 1] 를, 즉 visited3[cur - i + n - 1] 를 true 로 만들면 된다.
		// ex) (1,1) 과 (3,3) 은 x - y = 0 으로, 같은 대각선 상에 위치해있어서 두 퀸을 서로 공격하게 된다. (부적절한 배치)

		if (visited1[i] || visited2[i + cur] || visited3[cur - i + n - 1]) // 부적절한 퀸의 배치인 경우
			continue;   // 거기에는 퀸 배치 안함

		visited1[i] = 1;
		visited2[i + cur] = 1;
		visited3[cur - i + n - 1] = 1;

		func(cur + 1); 

		visited1[i] = 0;
		visited2[i + cur] = 0;
		visited3[cur - i + n - 1] = 0;
	}
}

int main(void)
{
	cin >> n;
	func(0);

	cout << cnt;
}