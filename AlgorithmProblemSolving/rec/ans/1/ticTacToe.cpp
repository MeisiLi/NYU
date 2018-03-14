#include <iostream>
using namespace std;
string a[3];
bool win() {
    for (int i = 0; i < 3; i++) {
        bool ok = a[i][0] != '.';
        for (int j = 1; j < 3; j++) {
            if (a[i][j] != a[i][j - 1]) ok = false;
        }
        if (ok) return true;
    }
    for (int j = 0; j < 3; j++) {
        bool ok = a[0][j] != '.';
        for (int i = 1; i < 3; i++) {
            if (a[i][j] != a[i - 1][j]) ok = false;
        }
        if (ok) return true;
    }
    bool ok = a[0][0] != '.';
    for (int i = 1; i < 3; i++) {
        if (a[i][i] != a[i - 1][i - 1]) ok = false;
    }
    if (ok) return true;
    ok = a[0][2] != '.';
    for (int i = 1; i < 3; i++) {
        if (a[i][2 - i] != a[i - 1][3 - i]) ok = false;
    }
    return ok;
}
string solve() {
    int x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 'X') x++;
            else if (a[i][j] == '0') o++;
        }
    }
    char cur = '.';
    if (x == o) {
        cur = '0';
    } else if (x == o + 1){
        cur = 'X';
    } else {
        return "illegal";
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == cur) {
                bool curWin = win();
                a[i][j] = '.';
                bool preWin = win();
                a[i][j] = cur;
                if (curWin && !preWin) {
                    if (cur == 'X') return "the first player won";
                    else return "the second player won";
                }
            }
        }
    }
    if (win()) return "illegal";
    if (o + x == 9) return "draw";
    return cur == 'X' ? "second" : "first";
}
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cout << solve() << endl;
    return 0;
}