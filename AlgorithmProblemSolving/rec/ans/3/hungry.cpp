#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        bool ok = false;
        for (int a = 0; a <= n / 3; a++) {
            int b = n - a * 3;
            if (b % 7 == 0) ok = true;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}