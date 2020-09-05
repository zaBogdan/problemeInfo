#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere.in");

int main(){
    int n,x,y,min=1000,max=-1000;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x >> y;
        max = x > max ? x : max;
        min = y < min ? y : min;
    }
    cout << max << ' ' << min;
    cout << endl; //development purpose.
    return 0;
} 