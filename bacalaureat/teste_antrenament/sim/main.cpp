#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    long long x=1,y=1;
    int n=170;
    while(x <= n){
        int z = y+2*x;
        x=y;
        y=z;
        if(z==n)
            ok=true;
    }
    if(x/2+1==n)
        cout << x/2+1 << ' ';
    else
        cout << "nu exista";
    cout << endl;
    return 0;
}