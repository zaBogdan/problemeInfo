#include <iostream>
using namespace std;

int divizor(int n){
    int prod=1;
    for(int i=3;i<=n/2;i+=2){
        if(n%i==0)
            prod*=i;
    }
    return prod;
}

int main(){
    int n,p=1,nr=0,cif;
    cin >> n;
    while(n){
        cif = n%10;
        if(cif%2==1)
            cif--;
        nr=nr+cif*p;
        p*=10;
        n/=10;
    }
    cout << nr;
    cout << endl;
    return 0;
}