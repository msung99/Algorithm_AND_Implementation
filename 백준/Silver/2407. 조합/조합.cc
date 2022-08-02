/*
조합을 하나씩 써보면 그 값이 파스칼의 삼각형과 똑같이 나오는 것이 보인다.

nCm = n-1Cm-1 + n-1Cm

조합을 계산할때 숫자가 너무 커져서 오버플로우가 발생한다. 따라서 string 끼리의 계산이 필요하다.
1의 자리끼리 계산하고, 10으로 나눈 나머지를 1의자리로 저장한다.

1의자리 계산 결과를 나누기 10하면, 올림수가 발생했는지 판단할 수 있다.
*/

#include <iostream>
using namespace std;

string arr[105][105];

string add(string num1, string num2) {
    string num = "";
    int sum = 0;
    int size = max(num1.size(), num2.size());

    for (int i = 0; i < size || sum; i++) {
        if (num1.size() > i) sum += num1[i] - '0';
        if (num2.size() > i) sum += num2[i] - '0';

        num += sum % 10 + '0';
        sum /= 10;
    }

    return num;
}

string combi(int n, int m) {
    if (n == m || m == 0) return "1";

    string& ans = arr[n][m];

    if (ans != "") return ans;

    ans = add(combi(n - 1, m - 1), combi(n - 1, m));

    return ans;
}

int main() {
    int n, m;

    cin >> n >> m;

    combi(n, m);

    for (int i = arr[n][m].size() - 1; i >= 0; i--)
        cout << arr[n][m][i];

    return 0;
}