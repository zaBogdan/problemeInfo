#include <iostream>
using namespace std;

int main(){
    int n,newn=0,p=1;
    cin >> n;
    while(n){
        int cif = n%10;
        if(cif%2==1)
            cif--;
        newn += cif*p;
        p*=10;
        n/=10;
    }
    cout << newn;
    cout << endl;
    return 0;
}