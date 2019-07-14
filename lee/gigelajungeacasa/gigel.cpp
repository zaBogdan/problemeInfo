#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 1010;
struct coord{int x,y;} casa,popas;
long long n,m,k;
int a[NMax][NMax];
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void read();
void bordare(){
    for(int i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-1;
    for(int i=0;i<=m+1;i++)
        a[0][i] = a[n+1][i] = -1;

}
void lee(){
    coord v[n*m+8001];
    memset(v,0,sizeof(v));
    int prim,ultim;
    prim = ultim = 1;
    v[prim].x = popas.x;
    v[prim].y = popas.y;
    a[v[prim].x][v[prim].y] = 0;
    while(prim<=ultim){
        for(int i=1;i<=8;i++)
            if(!a[v[prim].x+dx[i]][v[prim].y+dy[i]]){
                ultim++;
                v[ultim].x = v[prim].x+dx[i];
                v[ultim].y = v[prim].y+dy[i];
                a[v[ultim].x][v[ultim].y] = a[v[prim].x][v[prim].y]+1;
            }
        
        prim++;
    }
    ofstream g("gigelajungeacasa.out");
    g << a[casa.x][casa.y];
    g.close();
}

int main(){
    read();
    bordare();
    lee();
    return 0;
}

void read(){
    ifstream f("gigelajungeacasa.in");
    f >> n >> m >> k;
    f >> casa.x >> casa.y;
    f >> popas.x >> popas.y;
    int x,y;
    while(f >> x >> y)
        a[x][y] = -1;
    f.close();
}