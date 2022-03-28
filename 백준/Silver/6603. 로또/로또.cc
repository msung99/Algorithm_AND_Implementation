#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[15]; // 배열 num의 원소들의 인덱스를 저장하는 배열
int num[15];  // 실제 데이터가 저장되는 배열
bool visited[15];

void func(int k) {
    if (k == 6) {
        bool check = true;  // 사전 순으로 (오름차순으로) 정렬되어 있는지 체크하는 변수
        int prev = -1;
        for (int i = 0; i < 6; i++) {
            if (prev > num[arr[i]]) // 현재형(num[arr[i]) 이 직전의 항(tmp) 보다 작으면 사전 순(오름차순)이 아니다.
                check = false; 
            prev = num[arr[i]]; // 이전 노드 값 prev 최신화
        }

        // 사전 순으로 되어있다면 출력해준다.
        if (check) {
            for (int i = 0; i < 6; i++)
                cout << num[arr[i]] << " ";
            cout << '\n';
        }
        return;
    }

    // arr에는 0~N 사이의 k개의 숫자로 구성된 조합이 구성됨 
    for (int i = 0; i < n; i++) { 
        if (!visited[i]) {
            arr[k] = i;
            visited[i] = 1;
            func(k + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> num[i];

        sort(num, num + n);

        func(0);
        cout << "\n";

        fill(num, num + n, 0);
        fill(arr, arr + n, 0);
    }
}
