#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    string ans;
    cin >> ans;
    int pos = ans.find('*');
    string pre = ans.substr(0, pos);
    string end = ans.substr(pos + 1);

    while(t--) {
        string str;
        cin >> str;

        if(pre.size() + end.size() > str.size()) {
            cout << "NE\n";
        } else {
            if(pre == str.substr(0, pos) && end == str.substr(str.size() - end.size())) {
                cout << "DA\n"; 
            } else {
                cout << "NE\n";
            }
        }
    }
    return 0;
}