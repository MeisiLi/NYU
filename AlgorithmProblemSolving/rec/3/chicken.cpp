#include <iostream>
using namespace std;

int chunk;

bool solve(){
    if((chunk%7 == 0) || (chunk%3 == 0) || (chunk%7%3 == 0)) {
        return true;
    } else if(chunk > 7 && (chunk-7)%3 == 0){
        return true;
    }  else if(chunk > 14 && (chunk-14)%3 == 0){
        return true;
    } 
    return false;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> chunk;
        if(solve()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
   
	return 0;
}