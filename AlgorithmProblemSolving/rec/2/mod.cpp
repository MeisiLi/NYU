#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    unsigned long int n, m;
    cin >> n >> m;
    unsigned long int r = 2;
    for(long long i = 1; i < n; i++){
        r = r*2;
    }
    unsigned long int result = m % r;
    return 0;
}
