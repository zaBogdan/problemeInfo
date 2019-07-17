#include <iostream>
#include <cmath>
using namespace std;
int n,v[25];

void afisare(){
    for(int i=1;i<=n;i++)
        cout << v[i];
    cout << '\n';
}
bool valid(int k){
    if(k>1)
        if(abs(v[k]-v[k-1])!=1) //modulul diferentei este 1
            return 0;
    if(k==n && v[n]!=0) //ultima cifra este 0
        return 0;
    if(v[k]<0 || v[k]>9) //este cifra
        return 0;
    return 1;
}

void bkt(int k){
    if(k==n+1) afisare();
    else
        for(int i=v[k-1]-1;i<=v[k-1]+1;i+=2){
            v[k] = i;
            if(valid(k)) bkt(k+1);
        }
}

int main(){
    cin >> n;
    v[1] = 0;
    v[2] = 1;
    bkt(3);
    return 0;
}