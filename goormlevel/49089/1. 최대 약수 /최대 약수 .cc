#include <bits/stdc++.h>
using namespace std;

// 길이가 2이상인 임의의 구간 a ~ b 가 주어지면, 그 구간의 n 의 배수보다 2의 배수가 항상 같거나 더 많다.

int a, b;
unordered_map<int, int> dic;

int leastDivisor(int n) {
    for(int i=2; i*i <= n; i++) {
        if(n % i == 0) {
            return i;
        }
    }
    return n;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    if(a != b) {
        cout << 2; // 무조건 2의 배수가 가장 많음.
    } else {
        cout << leastDivisor(a); // 두 숫자가 서로 같은 경우, 2 다음으로 작은 약수를 구함.
    }

    return 0;
}