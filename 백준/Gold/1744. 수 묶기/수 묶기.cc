#include <bits/stdc++.h>
using namespace std;

long long ans;

void seqNum(vector<int> arr) {
    while(arr.size() > 1) {
        ans += *(arr.end() -1) * *(arr.end() - 2); // 가장 큰 숫자부터 2개씩 잘라서 곱하기
        arr.pop_back();
        arr.pop_back();
    }

    // 원소 개수가 홀수개였다면 마지막 1개가 남는다. 이 남은 원소 1개를 더해준다.
    if(arr.size()) {
        ans += arr[0];
    }
} 

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> seqP, seqN;

    int n, data;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> data;

        // 1은 곱하는것보다 그냥 더하는게 이득임 
        if(data == 1) {
            ans++;
        }

        // 양수 집합
        else if(data > 0) {
            seqP.push_back(data);
        }

        // 음수 집합 
        else {
            seqN.push_back(data);
        }
    }

    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<>()); // 음수 집합 역정렬

    // 양수, 음수 집합 각각에 대해 최댓값을 계산
    seqNum(seqP);
    seqNum(seqN);

    cout << ans;

    return 0;
}