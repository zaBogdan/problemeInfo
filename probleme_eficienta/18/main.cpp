#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");


int main(){
    int n,x,y,vmax,lmax=0,gmax=1;
    f >> n >> x;
    vmax = x;
    lmax = 1;
    while(f>>y){
        if(x==y)
            lmax++;
        else{
            if(gmax<lmax){
                gmax = lmax;
                vmax = x;
            }
            lmax = 1;
        }
        x=y;
    }
    cout << vmax << ' ' << gmax; 
    cout << endl; //development purpose
    return 0;
}