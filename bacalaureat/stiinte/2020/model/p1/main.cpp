#include <iostream>
using namespace std;

int main(){
    int n,x=0,p=1;
    bool impar=false;
    cin >> n;
    while(n){
        int c = n%10;
        if(c%2){
            x = x + c*p;
            p*=10;
            impar=true;
        }
        x = x + c*p;
        p*=10;
        n/=10;
    }
    if(impar)
        cout << x;
    else cout << -1;
    cout << endl;
    return 0;
}