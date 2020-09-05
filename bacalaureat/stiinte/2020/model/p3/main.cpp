#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("numere.in");

int main(){
    int x,y,lipsa=0;
    f >> x;
    while(f >> y){
        lipsa += x-y-1;
        x=y;
    }
    cout << lipsa;
    cout << endl;
    return 0;
}