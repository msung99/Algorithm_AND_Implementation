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
    
    stack<int> st;
    while(t--) {
        string s;
        int num;
        cin >> s;
        if(s == "push") {
            cin >> num;            
            st.push(num);
        } else if(s == "top") {
            if(st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
            }
        } else if (s == "empty") {
            if(st.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s == "pop") {
            if(st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if (s == "size") {
            cout << st.size() << "\n";            
        }
    }
}