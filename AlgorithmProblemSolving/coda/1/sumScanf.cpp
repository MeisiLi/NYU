#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <ctime>
#include <cassert>
#include <functional>
#include <list>
using namespace std;

#define MAXN 100001
#define STRMAX 31
#define REF(i, s, t)    for(i=(s); i<(t); ++i)
#define DEF(i, s, t)    for(i=(s-1); i>(t); i--)
#define ll  long long int
int N, M, a, b, i, j;

int main(){
    ios_base::sync_with_stdio(false);
    string line;
    char ch;
    int sum;
    while(scanf("%d", &N) != EOF){
        scanf("%c", &ch);
        sum += N;
        if(ch == '\n'){
            printf("%d\n", sum);
            sum = 0;
        }
    }
    return 0;
}
