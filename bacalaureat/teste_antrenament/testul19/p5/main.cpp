#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
ofstream g("bac.out");
const int nefericite[] = {0,4,16,20,37,42,58,89,145};

/*
Subprogramul verifica daca numarul este fericit sau nu.
Parametrii: 
    - n ( un numar natural pozitiv)
    - ap (contorizeaza pasii pe care ii fac, schimband variabila in memorie)
Returneaza:
    - 1 daca numarul este fericit
    - 0 daca se ajunge la unul din numerele "nefericite"
*/
int is_happy(int n,int &ap){
    //cazul fericit cand da unu
    if(n==1) return 1;
    //daca ajung la un caz de genul, inseamna ca numarul este nefericit
    for(int i=0;i<9;i++)
        if(n==nefericite[i])
            return 0;
    //am trecut testele acum cresc numarul de modificari.
    ap++;
    //daca e mai mica ca 10 nu trebuie sa il mai sparg in cifre => ridic la patrat
    if(n<10) return is_happy(n*n,ap);
    //daca e mai mare, fac suma cifrelor. 
    int s=0;
    while(n){
        s+=(n%10)*(n%10);
        n/=10;
    }
    return is_happy(s,ap);
}

int main(){
    int x;
    while(f >> x){
        //citesc din fisier si atat. N00b.
        int ap=0;
        if(is_happy(x,ap))
            g << x << ' ' << ap << '\n';
    }
    return 0;
}   