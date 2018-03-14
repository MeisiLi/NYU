#include<iostream>
#include<unordered_map>
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        unordered_map<int, int> mp;
        scanf("%d", &n);
        int x;
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            mp[a[i]]++;
            while (mp[a[i]] > 1) {
                mp[a[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        printf("%d\n", res);
    }
    return 0;
}