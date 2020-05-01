#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main()
{
    int x,y, counter;
    f >> x;
    counter = 1;
    while(f >> y){
        if(x==y)
            counter++;
        else{
            cout << x << ' ' << counter << ' ';
            counter = 1;
        }
        x=y;
    }
    cout << x << ' '  << counter;
    cout << endl;
}