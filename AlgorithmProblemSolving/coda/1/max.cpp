/* 
 * Problem: simpleMax in hw1
 * Meisi Li
 * Date: 4/10/2018
 */

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
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>
#include <list>
using namespace std;

#define IEF(i, s, t)    for(i=(s); i<(t); i++)
#define NEF(i, s, t)    for(i=(s); i!=(t); i++)
#define MAXN 100000
#define INF (int)1e9

int main(){
    ios_base::sync_with_stdio(false);
    int n, currNum, i, maxNum=-INF;
    cin >> n;
    IEF(i, 0, n){
        cin >> currNum;
        maxNum = max(maxNum, currNum);
    }
    cout << maxNum << endl;
    return 0;
}
