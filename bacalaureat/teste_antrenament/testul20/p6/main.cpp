#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,sumamax=0, suma=0;
    f >> x;
    suma=x;
    while(f >> y){
        if(x%2==y%2){
            suma+=y;
            if(sumamax<suma)
                sumamax=suma;
        }
        else 
            suma=y;
        x=y;
    }
    cout << sumamax;
    cout << endl;
    return 0;
}