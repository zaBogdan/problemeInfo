#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 105;
struct coord{int x, y;};
int n,m,a[NMax][NMax],aF[NMax][NMax],nr_zona,d[1005],minim = 100000;
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};

void read();
void solve();
bool proximity(int x,int y,int zona);
bool ok(int x,int y);
void fill(int x,int y);
int lee(int x,int y){
    int b[NMax][NMax];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]) b[i][j] = -1;
            else b[i][j]=0;
    for(int i=0;i<=n+1;i++)
        b[i][0] = b[i][m+1] = -1;
    for(int j=0;j<=m+1;j++)
        b[0][j] = b[n+1][j] = -1;
    coord v[n*m*2];
    memset(v,0,sizeof(v));
    int prim,ultim;
    prim = ultim = 1;
    v[prim].x = x;
    v[ultim].y = y;
    b[x][y] = 1;
    while(prim<=ultim){
        for(int i=1;i<=4;i++){
            int newX = v[prim].x+dx[i];
            int newY = v[prim].y+dy[i];
            if(a[newX][newY]==2) return b[v[prim].x][v[prim].y];
            else if(!b[newX][newY]){
                ultim++;
                v[ultim].x = newX;
                v[ultim].y = newY;
                b[newX][newY] = b[v[prim].x][v[prim].y]+1;
            }
        }
        prim++;
    }
    return 0;
}

int main(){
    read();
    solve();
    ofstream g("insule.out");
    for(int i=1;i<=3;i++)
        g << d[i] << ' ';
    g << minim;
    g.close();
    return 0;
}

void read(){
    ifstream f("insule.in");
    f >> n >> m;
    char c[105];
    f.getline(c,105);
    for(int i=1;i<=n;i++){
        f.getline(c,105);
        for(int j=1;j<=m;j++)
            a[i][j] = c[j-1]-'0';
    }
    f.close();
}
void fill(int x,int y){
    aF[x][y] = nr_zona;
    for(int i=1;i<=4;i++){
        int newX = x+dx[i];
        int newY = y+dy[i];
        if(ok(newX,newY) && !aF[newX][newY] && a[newX][newY]==a[x][y])
            fill(newX,newY);
    }
}
bool ok(int x,int y){
    if(x<1 || y <1)
        return 0;
    if(y>m || x>n)
        return 0;
    return 1;
}
void solve(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!aF[i][j] && a[i][j]){
                nr_zona=a[i][j];
                d[nr_zona]++;
                fill(i,j);
            }
    //eliminarea variabilelor inutile
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]==3) a[i][j] = -1;
        }
    //bordarea
    for(int i=0;i<=n+1;i++)
        a[i][0] = a[i][m+1] = -1;
    for(int j=0;j<=m+1;j++)
        a[0][j] = a[n+1][j] = -1;
    //cautare
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j] && proximity(i,j,1)){
                int nr = lee(i,j);
                if(nr<minim && nr)
                    minim = nr;
                // cout << lee(i,j) << ' ' << i << ' ' << j << endl;
            }

}
bool proximity(int x,int y,int zona){
    int nr=0;
    for(int i=1;i<=4;i++)
        if(a[x+dx[i]][y+dy[i]] == zona)
            nr++;
    if(!nr)
        return 0;
    nr = 0;
    for(int i=1;i<=4;i++)
        if(a[x+dx[i]][y+dy[i]] == 0)
            nr++;
    if(!nr)
        return 0;
    return 1;
}