#include <vector>
#include <stdio.h>
using namespace std;
const int N = 1005;
int n;
int vis[N];
int f[100];
int main() {
    for (int i = 0; i < N; i++) vis[i] = 0;
    f[1] = f[2] = 1;
    vis[1] = 1;
    for (int i = 3; ;i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= N) break;
        vis[f[i]] = 1;
    }
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            printf("%c", vis[i] ? 'O' : 'o');
        }
        puts("");
    }
    return 0;
}