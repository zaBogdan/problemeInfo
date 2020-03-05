#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
const int n = 100000;
int viz[n];

int main(){
    //ciur
    viz[0]=viz[1]=true;
    for(int i=2;i*i<=n;i++){
        if(!viz[i])
            for(int j=2;j<=n/i;j++)
                 viz[i*j]=true;
    }
    int x,prim1=0,prim2=0;
    while(f >> x){
        if(!viz[x]){
            prim2=prim1;
            prim1=x;
        }
    }
    if(prim1 && prim2) 
        cout << prim2 << ' ' << prim1;
    else cout << "Numere prime insuficiente";
    cout << endl; //development purpose.
    return 0;
} 