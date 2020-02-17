#include <iostream>
#include <fstream>
using namespace std;
ifstream f1("A.txt");
ifstream f2("B.txt");

int main(){
    //get the minim from the B file.
    int x, min_value=1000000000,counter=0;
    while(f2 >> x)
        if(x<min_value)
        min_value=x;
    while(f1 >> x)
        if(x < min_value)
            counter++;
    cout << counter;
    cout << endl; //development purpose
    return 0;
}