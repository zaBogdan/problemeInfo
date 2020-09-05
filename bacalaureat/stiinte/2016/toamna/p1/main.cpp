#include <iostream>
using namespace std;

int main(){
    int n, afisat=0,cn=0,p=1;
    cin >> n;
    while(n){
        int c=n%10;
        if(c%2==0){
            cn = cn+ p*c;
            p*=10;
        }
        cn = cn + p*c;
        p*=10;
        n/=10;
    }
    cout << cn;
    cout << endl;
    return 0;
}