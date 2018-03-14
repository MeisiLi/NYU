#include <vector>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int n;
long long solve() {
    stack<pair<int, int>> stk;
    long long res = 0;
    h[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        int idx = i;
        while (stk.size() && h[i] <= stk.top().first) {
            pair<int, int> cur = stk.top();
            stk.pop();
            int height = cur.first;
            int index = cur.second;
            res = max(res, 1ll * (height) * (i - index));
            idx = min(idx, index);
        }
        stk.push(make_pair(h[i], idx));
    }
    return res;
}
int main() {
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
        printf("%lld\n", solve());
    }
    return 0;
}
