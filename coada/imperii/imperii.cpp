#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 1006;
struct coord{int x,y;} v[1000001];
int n,m,a[NMax][NMax];
int A[NMax][NMax],B[NMax][NMax],C[NMax][NMax],D[NMax][NMax];

void read();
void bordare();
void minim(int i,int j){
    int minim = 0;
    int poz;
    minim = A[i][j];
    poz = 1;
    if(minim>B[i][j]){
        minim = B[i][j];
        poz = 2;
    }else if(minim==B[i][j])
        poz = 0;
    if(minim>C[i][j]){
        minim = C[i][j];
        poz = 3;
    }else if(minim==C[i][j])
        poz = 0;
    if(minim>D[i][j]){
        minim = D[i][j];
        poz = 4;
    }else if(minim==D[i][j])
        poz = 0;

    if(!poz)
        a[i][j]=0;
    if(poz==1)
        a[i][j]=a[1][1];
    if(poz==2)
        a[i][j] = a[1][m];
    if(poz==3)
        a[i][j] = a[n][1];
    if(poz==4)
        a[i][j] = a[n][m];


}
void lee(int X[NMax][NMax],int x,int y){
    memset(v,0,sizeof(v));
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            X[i][j]=a[i][j];
    int prim,ultim;
    prim = ultim =1;
    v[prim].x = x;
    v[prim].y = y;
    int pas = 1;
    X[v[prim].x][v[prim].y]=1;
    while(prim<=ultim){
        for(int k=0;k<4;k++)
            if(!X[v[prim].x+dx[k]][v[prim].y+dy[k]]){
                ultim++;
                v[ultim].x = v[prim].x+dx[k];
                v[ultim].y = v[prim].y+dy[k];
                X[v[ultim].x][v[ultim].y] = X[v[prim].x][v[prim].y]+1;
            }
        prim++;
    }

}

int main()
{
    read();
    bordare();
    lee(A,1,1);
    lee(B,1,m);
    lee(C,n,1);
    lee(D,n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j]){
                minim(i,j);
            }
    ofstream g("imperii.out");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(a[i][j]==0)
                g << "-";
            else if(a[i][j]==-1)
                g << "#";
            else
                g << (char) a[i][j];
        g << endl;
    }
    g.close();
    return 0;
}

void read(){
    ifstream f("imperii.in");
    f>> n >> m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char x;
        f>> x;
        if(x>='A' && x<='Z')
            a[i][j] = x;
        if(x=='-')
            a[i][j] = 0;
        if(x=='#')
            a[i][j] = -1;
    }

    f.close();
}
void bordare(){
    for(int i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-1;
    for(int j=0;j<=m+1;j++)
        a[0][j]=a[n+1][j]=-1;

}
