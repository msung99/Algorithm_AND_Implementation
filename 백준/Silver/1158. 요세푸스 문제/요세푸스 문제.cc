#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;   

    queue<int> q;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }

    cout << "<";
    while(q.size() > 1) {
        for(int i=0; i<k-1; i++) {
            int data = q.front();
            q.pop();
            q.push(data);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}
