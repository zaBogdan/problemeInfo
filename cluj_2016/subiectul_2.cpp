#include <iostream>
using namespace std;
int p=1;

int f(int a){
    if(a==0) return 0;
    int c = a%10;
    if(c%2==1){
        c = c*p;
        p*=10;
    }else c=0;
    return f(a/10)+c;
}


int main(){
    /*
        a) Problema extrage numerele impare si le pune in b in ordinea in care
        apar in numarul a. Daca a nu contine cifre impare returneaza 0.
        b) 13.
     */    
    cout << f(25476);
    return 0;
}