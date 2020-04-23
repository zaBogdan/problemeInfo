#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.txt");

bool verif(int n){
    while(n){
        if(
            n%10%2 && //prima cifra
            n/10%10%2 && //a doua cifra
            n/10/10%10%2 //a treia cifra
        )
        return 1;
        n /=10;
    }
    return 0;
}

int main(){
    int n,x;
    f >> n;
    for(int i=0;i<n;i++){
        f >> x;
        if(verif(x/1000)) //avand exact 6 cifre, putem trimite subprogramului x/1000
            cout << x << ' ';
    }
    cout << endl;
    return 0;
}