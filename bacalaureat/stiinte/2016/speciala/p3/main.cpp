#include <iostream>
using namespace std;

int main(){
    int x,y,n,i=3;
    cin >> x >> y;
    cout << y << ' ' << x << ' ';
    while(y!=1){
        if(x>0)
            x--;
        y = -x;
        x = y;
        cout << y << ' ';
    }
    cout << endl;
    return 0;
}