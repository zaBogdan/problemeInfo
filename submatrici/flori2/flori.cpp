#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int NMax = 200;
struct coord{ int e[NMax];} v[NMax];
int n,m,countee,a[NMax][NMax];
bool viz[NMax];

void read();
void search(int poz){
    countee++;
    int nr_e = 1;
    v[countee].e[nr_e] = poz;
    viz[poz] = true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int jj=1;jj<=m;jj++)
                if(a[poz][j]==a[i][jj] && !viz[i]){
                    nr_e++;
                    v[countee].e[nr_e] = i;
                    viz[i] = true;
                }
    v[countee].e[0] = nr_e;
}

int main(){
    read();
    for(int k=1;k<=n;k++)
        if(!viz[k])
            search(k);
    ofstream g("flori2.out");
    for(int i=1;i<=countee;i++){
        for(int j=1;j<=v[i].e[0];j++)
            g << v[i].e[j] << ' ';
        g << endl;
    }
    g.close();
    return 0;
}

void read(){
    ifstream f("flori2.in");
    f >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f >> a[i][j];

    f.close();
}