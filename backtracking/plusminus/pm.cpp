#include <iostream>
#include <fstream>
using namespace std;
ofstream g("plusminus.out");
int n,v[24],s;


bool valid();
void read();
void afiseaza(){
    if(valid()){
        for(int i=1;i<=n;i++)
            g << (v[i]==1 ? "-" : "+") << ' ';
        g << '\n';
    }
}
bool valid(){
    s=0;
    for(int i=1;i<=n;i++)
        if(v[i]==1)
            s = s-i*i;
        else s = s+i*i;
    if(s==n) return  1;
    return 0;
}
void bkt(int k){
    if(k==n+1) afiseaza();
    else
        for(int i=1;i<=2;i++){
            v[k]=i;
            bkt(k+1);
        }
}

int main(){
    read();
    if(n%4==0 || (n-1)%4==0)
        bkt(1);
    else g << "IMPOSIBIL";
    g.close();
    return 0;
}

void read(){
    ifstream f("plusminus.in");
    f >> n;
    f.close();
}