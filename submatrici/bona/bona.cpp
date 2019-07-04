#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 10005;
struct coord{int x,y;} a[NMax]; 
struct poz{coord ini,fini; } v[NMax]; 
int n,m;

void read();
bool search_free_toys(int i){
    if(v[i].ini.x == v[i].fini.x && v[i].ini.y == v[i].fini.y)
        return 1;
    for(int j=1;j<i;j++)
        if(i!=j){
            if(v[i].fini.x == v[j].ini.x)
                return 0;
            if(v[i].fini.y == v[j].ini.y)
                return 0;
        }
    cout << i << endl;
    return 1;
}

int main(){
    read();
    ofstream g("bona.out");
    int nrmin=0;
    for(int i=1;i<m;i++)
        if(search_free_toys(i))
            nrmin++;
    g << nrmin;
    g.close();
    return 0;
}

void read(){
    ifstream f("bona.in");
    f >> n >> m;
    for(int i=1;i<=m;i++){
        f >> v[i].ini.x >> v[i].ini.y;
        f >> v[i].fini.x >> v[i].fini.y;
    }
    f.close();
}