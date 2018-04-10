/* 
 * Problem: simpleSum in hw1
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

int main(){
    // this is really important because the cin and cout would slow down the speed
    ios_base::sync_with_stdio(false);
    int n, num;
    string line;
    while(getline(cin, line)){
        istringstream is( line );
        int sum = 0;
        while( is >> num )  sum += num;
        cout << sum << endl;
    }
    return 0;
}
