#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y;
    f >> x;
    while(f >> y){
        if(x!=y)
            cout << x << ' ';
        x=y;
    }
    cout << endl;   
    return 0;
}   