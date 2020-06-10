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
    int n,c1,c2;
    cin >> n;
    do{
        c1=n%10;
        n/=10;
        c2=n%10;
        if(c1>c2){
            c2=c1;
            c1=n%10;
        }
        while(c1<c2){
            cout << c1;
            c2/=2;
        }
    }while(n>9);
    cout << endl;
    return 0;
}