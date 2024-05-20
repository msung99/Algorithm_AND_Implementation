#include <bits/stdc++.h>
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*') return 2;
    return 0;
}

long long applyOp(long long a, long long b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
    return 0;
}

long long evaluate(string expression) {
    int i = 0;
    std::stack<long long> values;
    std::stack<char> ops;
    
    while (i < expression.length()) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
            long long val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                long long val2 = values.top();
                values.pop();
                long long val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
            i++;
        }
    }
    
    while (!ops.empty()) {
        long long val2 = values.top();
        values.pop();
        long long val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    
    return values.top();
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << max(evaluate(s1), evaluate(s2));
    
    return 0;
}
