#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int n, first, x,poz=1;
    f >> n >> first;
    for(int i=2;i<=n;i++){
        f >> x;
        if(x<first)
            poz++;
    }
    cout << poz;
    cout << endl; //development purpose.
    return 0;
} 