#include <iostream>
#include <fstream>
using namespace std;
ifstream f("medii.txt");

int cifra(float x){
    int y = (int)x; // sau int y = floor(x)%10;
    return y%10;
}

int main(){
    float x,y;
    int nr=0;
    while(f >> x >> y){
        if(cifra(x)+1==cifra(y))
            nr++;
    }
    cout << nr;
    cout << endl;
    return 0;
}