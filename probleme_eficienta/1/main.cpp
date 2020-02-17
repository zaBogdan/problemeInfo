#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    long long counter=0, x, y=-1;
    f >> y;
    counter = 1;
    while(f >> x){
        if(x==y)
            counter++;
        else {
            cout << y << ' ' << counter << ' '; 
            counter = 1;
            y=x;
        }
    }
    cout << y << ' ' << counter << ' '; //print the last case. 
    cout << endl; //development purpose
    return 0;
}