#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

bool prim(int x){
    if(x==0 || x==1)
        return 0;
    if(x%2==0 && x!=2)
        return 0;
    if(x==2) return 1;
    for(int i=3;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main(){
    int x,max=0,ap=0;
    while(f>>x){
        if(prim(x)){
            if(max < x){
                max = x;
                ap=1;
            }else if(max==x)
                ap++;
        }
    }
    cout << max << ' ' << ap;
    cout << endl; //development purpose.
    return 0;
}