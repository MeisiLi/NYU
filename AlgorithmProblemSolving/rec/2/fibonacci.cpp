#include <iostream>
using namespace std;

void getName(int n);
int fibon(int n);

int main(){
    int n;
    cin >> n;
    getName(n);
    return 0;
}

void getName(int n){
    int len = n;
    for(int i = 0; len > 0; i++){
        int numC = fibon(i);
        for(int j = 0; j < numC && len > 0; j++){
            if(j == 0){ cout << "O";    }
            else{   cout << "o";    }
            len--;
        }
    }
    cout << endl;
}

int fibon(int n){    
    if(n <= 1){
        return 1;
    } else {
        return fibon(n-1)+fibon(n-2);
    }
}
