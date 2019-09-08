#include <iostream>
using namespace std;

// Punctul c)
bool cifreConsecutive(int n){
    while(n){
        if(n%10==(n/10)%10)
            return 1;
        n/=10;
    }
    return 0;
}
bool sameNumbers(int n,int m){
    int fn[10],fm[10];
    for(int i=0;i<=9;i++)
        fn[i]=0,fm[i]=0;
    /*
        Folosim doi vectori de frecventa unul pentru cifrele lui N si unul pentru cele ale lui M
        In timpul descompunerii vom pune 1 daca pe pozitia respecitiva numarul are cifra. 
        Cifrele care nu exista in numar vor avea 0 in vector. 
        
        Daca doar una dintre ele este 1 va returna 0, iar la final daca ambele au aceleasi cifre
        va returna 1. 
     */
    while(n){
        if(n)
        fn[n%10]=1,
        n/=10;
    }
    while(m){
        fm[m%10]=1;
        m/=10;
    }
    for(int i=0;i<=9;i++)
        if((fn[i] || fm[i]) && fn[i]!=fm[i])
            return 0;
    return 1;
}
//Punctul d)
int powers(int n){
    
}

int main(){

    /*
    Punctul a)
    Punctul b) (n/100)%10
    */
   int n,m;
   cin >> n >>m;
   cout << sameNumbers(n,m) << endl;

    return 0;
}