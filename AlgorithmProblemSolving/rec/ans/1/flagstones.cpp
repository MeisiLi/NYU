#include <iostream>
using namespace std;
int n, m, a;
int main() {
  while (cin >> n >> m >> a) {
      cout << 1ll * ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
  }
  return 0;
}