#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

int sfx(int x){
    if(
        x%10<x/10%10 && //daca ultima cif < cifra zecilor
        x/10%10<x/10/10%10 //daca cifra zecilor < cifra sutelor
    )
    return 1;
    return 0;
}

int main(){
    int x,nr=0;
    while(f >> x)
    //daca n e 236543
        if(
            sfx(x) && //ultimele 3 (543)
            sfx(x/1000) && //primele 3 cifre (236) 
            x/10/10%10<x/10/10/10%10
        )
        nr++;
    // se mai putea si apeluri repetate la sfx,
    // sfx(x, x/10,x/100,x/1000)
    cout << nr;
    cout << endl;
    return 0;
}