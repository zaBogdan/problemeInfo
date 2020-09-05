#include <iostream>
#include <fstream>
using namespace std;
ofstream g("partitiinumar4.out");
int suma,n,elem[100],v[100],ok,s;

void read();
void afiseaza(int k){
        for(int i=1;i<=k;i++)
            g << v[i] << ' ';
        g << endl;
}

bool valid(int k){
    if(k>1)
        if(v[k]<v[k-1])
            return 0;
    s = 0;
    for(int i=1;i<=k;i++)
        s+= v[i];
    if(s<=suma)
        return 1;
    return 0;
}

void bkt(int k){
    if(suma==s) afiseaza(k-1);
    else
        for(int i=1;i<=n;i++){
            v[k]=elem[i];
            if(valid(k)) bkt(k+1);
        }
}

int main(){
    read();
    bkt(1);
    g.close();
    return 0;
}

void read(){
    ifstream f("partitiinumar4.in");
    f >> suma >> n;
    for(int i=1;i<=n;i++)
        f >> elem[i];
    bool sortat;
    do{
        sortat=true;
        for(int i=1;i<n;i++)
            if(elem[i]>elem[i+1])
                sortat=false,swap(elem[i],elem[i+1]);
    }while(!sortat);
    f.close();
}