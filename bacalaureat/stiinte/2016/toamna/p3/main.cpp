#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,z,lx,ly;
    f >> x >> y;
    while(f >> z){
        if(x%2==1 && y%2==0 && z%2==0){
            lx = y;
            ly = z;
        }
        x=y;
        y=z;
    }
    cout << lx << ' ' << ly;

    cout << endl;
    return 0;
}