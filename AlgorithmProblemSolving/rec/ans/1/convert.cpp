#include <vector>
#include <iostream>
using namespace std;
int n;
int main() {
    while (cin >> n) {
        vector<int> res;
        while (n) {
            res.push_back(n % 2);
            n /= 2;
        }
        for (int i = (int)res.size() - 1; i >= 0; i--) {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}