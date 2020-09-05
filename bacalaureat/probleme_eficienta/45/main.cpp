#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int fr[100];

int main(){
    int x,mip=100,mii=100,map=0,mai=0;
    while(f >> x){
        fr[x]=1;
        if(x%2==0){
            mip = mip>x ? x : mip;
            map = map<x ? x : map;
        }else{
            mii =  mii>x ? x : mii;
            mai =  mai<x ? x : mai;
        }
    }
    for(int i=mii;i<=mai;i++)
        if(fr[i] && i%2==1)
            g << i << ' ';
    g << endl;
    for(int i=map;i>=mip;i--)
        if(fr[i] && i%2==0)
            g << i << ' ';
        
    cout << endl; //development purpose.
    return 0;
} 