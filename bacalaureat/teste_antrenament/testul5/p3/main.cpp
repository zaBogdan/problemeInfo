#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,smax=0,suma=0;
    f >> x;
    if(x>=0)
        suma +=x;
    while(f >> y){
        if(y>=0)
            suma+=y;
        else{
            if(smax<suma)
                smax=suma;
            suma=0;
        }
        x=y;
    }
    if(smax<suma)
        smax=suma;
    cout << smax;
    cout << endl;   
    return 0;
}