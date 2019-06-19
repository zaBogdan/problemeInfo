#include <iostream>
using namespace std;

int celebritati(int n, int a[100][100]){
    int subscriptions=0, followers=0,celebrities=0;
    for(int p=1;p<=n;p++){
        for(int i=1;i<=n;i++)
            subscriptions+=a[p][i];
        for(int i=1;i<=n;i++)
            followers+=a[i][p];
        if(followers>subscriptions)
            celebrities++;
    }
    return celebrities;
}

int clici(int n, int a[100][100]){
    int clici=0;
    for(int i=1;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;j<=n;k++)
                if(a[i][j]*a[j][i]+a[i][k]*a[k][i]+a[j][k]*a[k][j]==3) //varianta 3
                    clici++;
    return clici;
}

int main(){
    //subpunctul a) ii (2) deoarece este un graf orientat iar urmaritorii sunt pe coloana.
    //iar cei pe care ii urmareste sunt pe linia respectiva. Mergem de la 1-n pe a[j][i],
    // i fiind constant.

    //subpunctul c) 
    /*
        1 (i) -> daca suma lor e 6 inseamna ca e un circuit inchis si toti se urmaresc intre ei.
        2 (ii) -> NU deoarece asta ar insemna ca primul ii urmareste pe 2 si 3, iar 2 pe 3, 
        ei nu se urmaresc reciproc.
        3 (iii) -> acelasi caz ca si la 1 (i)... daca se urmaresc reciproc produsul este 1, daca unul
        nu il urmareste pe celalt este 0. Daca toate 3 produsele sunt 1 -> se urmaresc reciproc.
        4 (iv) -> daca toti se urmaresc intre ei produsul este 1. Daca unul dintre ei nu il urmareste
        pe celalt produsul este 0.
        5 (v) -> Nu are niciodata cum sa fie 6 suma patratelor, valurile fiind doar 1 sau 0.

        Raspuns: i, iii, iv.
    
     */
    cout << f(12,9);
    return 0;
}