#include <iostream>
#include <cstring>
using namespace std;
const int NMax = 1000020;

void primes(bool nr[],int n){
    nr[0]=true,nr[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!nr[i]){
            for(int j=2;j<=n/i;j++)
                nr[i*j] = true;
        }
    }
}

int main(){
    bool prime[NMax];
    memset(prime,0,NMax);
    primes(prime);
    for(int i=1;i<=100;i++)
        if(!prime[i])
            cout << i << ' ';
    return 0;
}