#include <iostream>
using namespace std;

int main(){
    int n,p=1,cn=0;
    cin >> n;
    while(n){
        int c = n%10;
        if(c%2==0){
            cn = cn + c*p*10 + (c/2)*p;
            p*=10; 
        }
        else cn = cn + c*p;
        p*=10;
        n/=10;
    }
    cout << cn;
    cout << endl;
    return 0;
}