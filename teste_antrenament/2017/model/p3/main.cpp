#include <iostream>
#include <fstream> 
using namespace std;
ofstream g("bac.txt");

int main(){
    int x,y;
    cin >> x >> y;
    while(x!=y){
        g << y << ' ';
        if(y%2==0)
            y--;
        else
            y = (y-1)/2;
    }
    g << y;
    cout << endl;
    return 0;
}