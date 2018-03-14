#include <iostream>
using namespace std;
int a, b;
int main() {
    while (cin >> a >> b) {
        a *= b;
        if (a % 2 == 1) cout << "Odd" << endl;
        else cout << "Even" << endl;
    }
    return 0;
}