#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");

int main(){
    long long x, min1 = 999999999,min2= 999999999;
    while ( f >> x ){
        if((x<100 && x > 9) || (x < -9 && x > -100))
            if(x<min1) //Cele mai mici doua numere trebuie sa fie diferite? 
                min2=min1,min1=x;
    }
    cout << min1 << ' ' << min2;
    cout << endl;//testing
    return 0;
}