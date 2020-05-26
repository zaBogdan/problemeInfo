#include <iostream>
using namespace std;

int armstrong(int n){
    int s = 0,cn=n;
    while(cn){
        short cif = cn%10;
        s = s + cif*cif*cif;
        cn/=10;
    }
    return s==n;
}

int main(){
    cout << armstrong(153);
    cout << endl;   
    return 0;
}   