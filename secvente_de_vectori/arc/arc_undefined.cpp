#include <iostream>
#include <fstream>
using namespace std;
ofstream g("arc.out");
const int NMax = 10001;

int maxim(int m, int lenght[]){
    int maxim = -1,poz_maxim=1;
    for(int i=1;i<=m;i++)
        if(maxim<lenght[i]){
            maxim = lenght[i];
            poz_maxim = i;
        }
    return poz_maxim;
}
void read(int &c,int &n,int &m,int v[],int lenght[]);
void remove(int i){

}
void eliminate(int n,int m,int v[],int lenght[]){
    int poz_maxim = maxim(m,lenght);
    while(n>0 && lenght[poz_maxim]>=3){
        remove(poz_maxim);
        if(poz_maxim>0)
            poz_maxim=maxim(m,lenght);
    }
    if(n>0){
        cout << n << endl;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=lenght[i])
    }
}

int main(){
    int c,n,m,v[NMax],lenght[NMax];
    read(c,n,m,v,lenght);

    if(c==1)
        g << m;
    else eliminate(n,m,v,lenght);

    return 0;
}

void read(int &c,int &n,int v[],int lenght[]){
    ifstream f("arc.in");
    f >> c >> n;
    int last=-1;
    lenght[m]=1;
    for(int i=1;i<=n;i++){
        f >> v[i];
        if(last==v[i]){
            lenght[m]++;
        }else{
            last = v[i];
            m++;
        }
    }
    f.close();
}