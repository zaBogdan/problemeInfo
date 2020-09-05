#include <iostream>
using namespace std;

int main(){
    int x,y,n;
    x=1,y=1;
    cin >> n;
    int poz=3;
    while(poz<=n){
        int z = x+y;
        x = y;
        y = z;
        if(z%2==1)
            poz++;
    }
    cout << y;
    
    cout << endl;
    return 0;
}