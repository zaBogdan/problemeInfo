#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int x, par1=0,par2=0;
    while(f >> x)
        if(x%2==0){
            if(par1<x){
                par2=par1;
                par1=x;
            }
            //merge si fara iful asta.
            else if(par2 < x){
                par2 = x;
            }
        }
    cout << par1 << ' ' << par2;
    cout << endl; //development purpose.
    return 0;
}