#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,ap=0;
    f >> x;
    while(f >> y){
        if(x==y)
            ap++;
        else{
            if(!ap)
                cout << x << ' ';
            ap=0;
        }
        x=y;
    }
    if(!ap)
        cout << x << ' ';
    cout << endl;   
    return 0;
}