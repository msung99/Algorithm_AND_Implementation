#include <iostream>
#include <string>
using namespace std;

// 팰린드롬 검사 함수
bool isPalindrome(const string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 유사 팰린드롬 검사 함수
bool isPseudoPalindrome(const string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            // 한 문자를 제외하고 팰린드롬인지 확인
            return isPalindrome(str.substr(left + 1, right - left)) || isPalindrome(str.substr(left, right - left));
        }
        left++;
        right--;
    }
    return false; // 사실상 이 줄은 도달하지 않음, 모든 문자 같으면 이미 팰린드롬이기 때문
}

int main() {
    int t;
    cin >> t; // 테스트 케이스의 수 입력

    while (t--) {
        string s;
        cin >> s; // 문자열 입력
        if (isPalindrome(s)) {
            cout << 0 << "\n"; // 팰린드롬이면 2 출력
        } else if (isPseudoPalindrome(s)) {
            cout << 1 << endl; // 유사 팰린드롬이면 1 출력
        } else {
            cout << 2 << "\n"; // 팰린드롬도 유사 팰린드롬도 아니면 0 출력
        }
    }

    return 0;
}
