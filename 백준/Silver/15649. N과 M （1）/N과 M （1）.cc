#include <iostream>
using namespace std;

int n, m;
int arr[10]; // 수열을 담을 배열
bool is_used[10]; // 특정 수가 쓰였는지를 나타내는 true 또는 false 로 나타내는 배열

// ex) n = 4, m = 3 에서 arr 에 현재 상태가 3 2 가 채워진 상태라고 한다면
//  arr[0] = 3, arr[1] = 2 이고
// is_used[0] = false, is_used[1] = true, is_used[2] = true, is_used[3] = false 가 된다.


// func : 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수

//  맨 처음에는 수를 한개도 택하지 않았으니 func(0)을 호출한다.
//  func(0) 은 arr[0] 을 정한후에 func(1) 을 호출한다. 

void func(int k) { // 현재 k개까지 수를 택했음 (배열 arr에 k개의 숫자가 들어있다)
    if (k == m) { // m개를 모두 택했으면   => 재귀 함수이므로 base condition 이 필요.  k == m이 되었을때 m개를 모두 택했으니 수열을 출력한 후 함수를 종료하면 된다.
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
        if (!is_used[i]) { // 아직 i가 사용되지 않았으면
            arr[k] = i; // k번째 수를 i로 정함
            is_used[i] = 1; // i를 사용되었다고 표시
            func(k + 1); // 다음 수를 정하러 한 단계 더 들어감 
            is_used[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
            // => 백트래킹의 규칙 : 재귀문을 돌고나서 방문 기록을 다시 false 로 초기화시키는 코드가 필요함.
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}
