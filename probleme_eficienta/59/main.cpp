#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere.in");

int main(){
    int n,interval=1;
    float x,y;
    f >> n >> x;
    for(int i=2;i<=n;i++){
        f >> y;
        if(floor(x)!=floor(y)){
            if(ceil(x)!=y)
            interval++;
        }
        x=y;
    }
    cout << interval;
    cout << endl; //development purpose.
    return 0;
} 