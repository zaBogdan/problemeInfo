#include <iostream>
#include <cstring>
using namespace std;
int fr[1000000000];

int factori(int n, int m){
    //ciurul lui Eratosthenes
    int max = n>m ? n : m;
    fr[0]=fr[1]=1;
    for(int i=2;i*i<=max;i++){
        if(!fr[i]){
            for(int j=2;j<=max/i;j++)
                fr[i*j]=1;
        }
    }
    //initializarea frecventelor.
    int valori[max/2+1],nr=0;
    memset(valori, 0, max/2+1);
    for(int i=2;i<=n/2;i++)
        if(n%i==0 && fr[i]==0) //daca e divizibil si prim 
            valori[i]++;
    for(int i=2;i<=m/2;i++)
        if(m%i==0 && !fr[i]&&valori[i]) //daca e divizibil, prim si daca e in descompunerea celuiltalt.
            nr++;
    return nr;
}

int main(){
    cout << factori(750, 490) << endl;
    return 0;
}