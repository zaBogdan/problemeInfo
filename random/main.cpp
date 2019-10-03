#include <iostream>
using namespace std;

int f(int n){
    while(n>100){
        int x = n%10, y=(n/10)%10, z =(n/100)%10;
        if(x%2==1 && y%2==1 && z%2==1)
            return 1;
        n = n/10;
    }
    return 0;
}

int main(){
    cout << f(1532527) << endl;
    return 0;
}