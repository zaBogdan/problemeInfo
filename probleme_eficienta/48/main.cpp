#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("date.in");
int v[100];

int generateFibonnaci(int cif,int nr){
    int first = cif;
    int second = cif;
    while(second<nr){
        int third = first+second;
        first = second;
        second = third;
    }
    return second-first;
}
int main(){
    int x,k,nr;
    int p=1;
    f >> x >> k;
    f >> nr;
    int cif = (x/10%10 != 0);
    for(int i=1;i<=generateFibonnaci(cif+1,k);i++)
        p*=10;
    cout << p << endl;
    cout << nr/p;
    cout << endl; //development purpose.
    return 0;
} 