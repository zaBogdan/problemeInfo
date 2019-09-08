#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream g("paranteze.out");
int n,v[25];

void read();
bool valid(){
    int fr[25];
    memset(fr, 0, sizeof(fr));    
    for(int i=1;i<n;i++)//merg pana la penultima
        if(v[i]==1)
            for(int j=i+1;j<=n;j++)//caut paranteza inchisa, care sa nu mai fie luata incaodata
                if(v[j]==2 && !fr[j]){
                    fr[i]=1;
                    fr[j]=1;
                    j=n+1;
                }
    for(int i=1;i<=n;i++)
        if(!fr[i])
            return 0;
    return 1;
}
void afisare(){
    if(valid()){
        for(int i=1;i<=n;i++)
            g << (v[i]==1? "(":")");
        g << '\n';
    }
}

void bkt(int k){
    if(k==n+1) afisare();
    else{
        for(int i=1;i<=2;i++){
            v[k]=i;
            bkt(k+1);
        }
    }
}

int main(){
    read();
    v[1]=1;
    if(n%2==0)
        bkt(2);
    g.close();
    return 0;
}

void read(){
    ifstream f("paranteze.in");
    f >> n;
    f.close();
}