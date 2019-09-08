#include <iostream>
using namespace std;

int f(int a,int b){
    if(a==b) return a;
    if(a>b) return f(a-b,b);
    if(a<b) return f(a,b-a);
}

int main(){

    //f(12,9)
    //f(3,9)
    //f(3,6)
    //f(3,3)
    //Relatia de recurenta da cel mai mic divizor comun al celor doua numere a si b
    //prin scaderi repetate. 
    cout << f(12,9);
    return 0;
}