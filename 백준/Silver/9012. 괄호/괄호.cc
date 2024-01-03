#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;

        stack<char> st;
        for(int i=0; i< str.size(); i++) {
            if(str[i] == '(') {
                st.push('(');
            } else if(str[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(')');
                }
            }
        }
        if(st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}