#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,s=0, smax=0;
    f >> x;
    if(x<0)
        s+=x;
    while(f >> y){
        if(y<0)
            s+=y;
        else{
            if(s<smax)
                smax=s;
            s=0;
        }
        x=y;
    }
    if(s<smax)
        smax=s;
    cout << smax;
    cout << endl;
    return 0;
}