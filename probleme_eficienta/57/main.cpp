#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere.in");

int main(){
    int n,min=1000000;  
    float x,y;
    f >> n >> x;
    while(f>>y){
        int dif = floor(y)-ceil(x);
        if(dif==1 && floor(y)!=y)//daca am numar intreg in intervalul deschis. 
                dif++;
        min = dif<min ? dif : min;
        x=y;
    }
    cout << min;
    cout << endl; //development purpose.
    return 0;
} 