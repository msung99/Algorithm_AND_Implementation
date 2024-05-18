// 문제 조건: "연속해서 두 개 이상의 연산자가 나타나지 않고", "식의 값을 최소로 만드는"
// '-' 뒤에 오는 식을 전부 뺄셈 처리하면 식의 값이 최소가 된다.
#include <bits/stdc++.h>
using namespace std;

int sign = 1;
int tmp, ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for(char c : s) {
        if(c == '+' || c == '-') {
            ans += sign * tmp;

            // '-' 뒤에 오는 식을 전부 뺄셈 처리 해버리기 위해 sign = -1 로 셋팅
            if(c == '-') {
                sign = -1;
            }
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
}