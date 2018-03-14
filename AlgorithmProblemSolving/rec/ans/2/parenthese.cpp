#include <vector>
#include <stdio.h>
#include <stack>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
string s;
bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}
bool solve() {
    stack<char> stk;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            stk.push(s[i]);
        } else {
            if (stk.size() == 0) return false;
            if (!match(stk.top(), s[i])) return false;
            stk.pop();
        }
    }
    return stk.size() == 0;
}
int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        getline(cin, s);
        if (s == "") {
            puts("Yes");
            continue;
        }
        puts(solve() ? "Yes" : "No");
    }

    return 0;
}