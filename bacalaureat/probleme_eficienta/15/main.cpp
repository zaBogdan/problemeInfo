#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");

int main(){
    int n,x,y;
    f >> n >> x;
    cout << x << ' ';
    for(int i=1;i<n;i++){
        f >> y;
        if(x!=y)
            cout << y << ' ';
        x=y;
    }
    cout << endl; //development purpose
    return 0;
}