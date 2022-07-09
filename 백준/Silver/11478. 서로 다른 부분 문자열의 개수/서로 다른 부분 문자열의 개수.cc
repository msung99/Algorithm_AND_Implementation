#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> set; // 중복을 제거하면서 문자열을 생성

    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
        str = "";
    }

    cout << set.size();
}