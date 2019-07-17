#include <iostream>
#include <cmath>
using namespace std;
int n,v[30];

void afisare(){
    for(int i=1;i<=n;i++)
        cout << (char) v[i];
    cout << '\n';
}
bool valid(int k){
    if(k>1)
    if(abs(v[k]-v[k-1])!=1) //diferenta de 1
        return 0;
    if(k==n && v[n]!='a') //ultima litera a
        return 0;
    if(v[k]<'a' || v[k]>'z') //literele mici ale alfabetului
        return 0;
    return 1;
}
void bkt(int k){
    if(k==n+1)  afisare();
    else
    for(int i=v[k-1]-1;i<=v[k-1]+1;i+=2){
        v[k] = i;
        if(valid(k))
            bkt(k+1);
    }
}

int main(){
    cin >> n;
    v[1] = 'a';
    v[2] = 'b';
    bkt(3);
    return 0;
}
