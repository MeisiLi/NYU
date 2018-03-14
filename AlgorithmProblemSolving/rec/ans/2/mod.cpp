#include <vector>
#include <stdio.h>
using namespace std;
int n, m;
int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (n >= 30) n = 30;
        printf("%d\n", m % (1 << n));
    }
    return 0;
}