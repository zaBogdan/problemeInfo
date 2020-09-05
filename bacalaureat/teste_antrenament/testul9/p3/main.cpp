#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int k,x,y,smax=0,s=0;
    f >> k >> x;
    if(x%k==0)
        s++;
    while(f>>y){
        if(y%k==0)
            s++;
        else{
            if(smax<s)
                smax=s;
            s=0;
        }
        x=y;
    }
    if(smax<s)
        smax=s;
    cout << smax;
    cout << endl;
    return 0;
}