#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int x,nr,poz=1,found=0;
    cin >> nr;
    while(f >> x){
        if(x>nr)
            poz++;
        if(x==nr)
            found=1;
    }
    if(found)
    cout << poz;
    else cout << "Nu exista";
    cout << endl; //development purpose.
    return 0;
} 