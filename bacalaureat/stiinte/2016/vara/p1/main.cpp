#include <iostream>
using namespace std;

int main(){
    int n,p=1,n2=0,ok=0;
    cin >> n;
    int cn=n;
    while(n){
        int c=n%10;
        if(c%2==0){
            n2 = n2+c*p;
            p*=10;
            ok=1;
        }
        n/=10;
    }
    if(n2==cn || !ok)
        cout << -1;
    else
        cout << n2;
    cout << endl;
    return 0;
}