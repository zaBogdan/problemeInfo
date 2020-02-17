#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");

bool palindrom(int n){
    int inv=0,m=n;
    while(n){
        inv= inv*10+n%10;
        n/=10;
    }
    return inv==m;
}
int main(){
    int n,x,pmax=0,plen=0;
    while(f >> x){
        if(palindrom(x)){
            if(x>pmax){
                pmax=x;
                plen=1;
            }
            if(x==pmax)
                plen++;
        }
    }
    g << pmax << ' ' << plen;
    cout << endl; //development purpose
    return 0;
}