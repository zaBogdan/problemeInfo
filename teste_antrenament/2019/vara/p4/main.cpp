#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,max=0,contor=0;
    f >> x;
    max=x;
    cout << max << ' ';
    while(f >> y){
        if(max<y){
            cout << y << ' ';
            max=y;
        }
        else if(max==y){
            if(x==y && !contor)
                cout << y << ' ';
            else
                contor=1;
        }else
            contor=0;
        x=y;
    }
    cout << endl;
    return 0;
}