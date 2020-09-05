#include <iostream>
using namespace std;

bool numar(int n){
    int nr=0,par=0,impar=0;
    while(n){
        int c = n%10;
        if(nr%2==0)
            par+=c;
        else
            impar+=c;
        n/=10;
        nr++;
    }
    return (par==impar);
    // if(par==impar)
    //     return true;
    // return false;    
}

void echilibrat(int a,int b){
    bool afisat = false;
    for(int i=b;i>=a;i--){
        bool ok=numar(i);
        if(ok){
            afisat=true;
            cout << i <<' ';
        }
    }
    if(!afisat)
        cout << "nu exista";
}

int main(){
    echilibrat(100,1500);
    cout << endl;
    return 0;
}