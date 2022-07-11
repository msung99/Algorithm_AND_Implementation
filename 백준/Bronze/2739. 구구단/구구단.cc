#include <iostream>
using namespace std;
/*
2 * 1 = 2
2 * 2 = 4
2 * 3 = 6
2 * 4 = 8
2 * 5 = 10
2 * 6 = 12
2 * 7 = 14
2 * 8 = 16
2 * 9 = 18
*/

int main(void)
{
    int n;
    cin >> n;
    for(int i = 1; i <= 9; i++){
        cout << n << " * " << i << " = " << n*i << '\n';
    }
}