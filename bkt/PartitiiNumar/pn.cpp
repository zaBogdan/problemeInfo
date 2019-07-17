#include <iostream>
#include <fstream>
using namespace std;
ifstream f("partitiinumar.in");
ofstream g("partitiinumar.out");
int n,v[45],s;

void afisare(int k){
    for(int i=1;i<=k;i++)
        g << v[i] << ' ';
    g << '\n';
}
bool valid(int k){
    s = 0;
    if(v[k]<v[k-1]) return 0; //Trebuie sa fie in ordine crescatoare
    for(int i=1;i<=k;i++)
        s+=v[i];
    if(s<=n) return 1; //suma mai mica sau egala cu n
    return 0;
}

void bkt(int k){
    if(s==n) afisare(k-1);
    else{
        for(int i=1;i<=n-k+1;i++){ //parcurg pana la diferenta 
            v[k] = i;
            if(valid(k))
                bkt(k+1);
        }
    }
}

int main(){
    f >> n;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
