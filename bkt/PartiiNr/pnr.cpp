#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int n,s,v[105];
ofstream g("partitiinr.out");

void afiseaza(int k){
    for(int i=1;i<=k;i++)
        g << v[i] << ' ';
    g << '\n';
}
bool valid(int k){
    s = 0;
    if(k>1)
        if(v[k-1]>v[k] || v[k]-v[k-1]<2)
            return 0;
    for(int i=1;i<k;i++)
        if(v[i]==v[k])
            return 0;
    for(int i=1;i<=k;i++)
        s+=v[i];
    if(s<=n)
        return 1;
    return 0;
}

void bkt(int k){
    if(s==n) afiseaza(k-1);
    else{
        for(int i=1;i<=n-k+1;i++){
            v[k] = i;
            if(valid(k)) bkt(k+1);
        }
    }
}

int main(){
    ifstream f("partitiinr.in");
    f >> n;
    f.close();
    bkt(1);
    g.close();
    return 0;
}