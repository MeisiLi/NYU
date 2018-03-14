#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int main() {
    cin >> n;
    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mi = min(mi, a[i]);
    }
    int pre = -1;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (mi == a[i]) {
        if (pre != -1) {
          res = min(res, i - pre);
        }
        pre = i;
      }
    }
    cout << res << endl;
    return 0;
}