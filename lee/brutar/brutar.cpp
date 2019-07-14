#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax=1005;
struct coord{int x,y;} v[1000001],b;
int n,m,a[NMax][NMax],poz=5;
int dx[8] = {0, -1, 0, 1, 0};
int dy[8] = {0,  0, 1, 0,-1};
void read();

void append_vector(char c[]);
void bordare();
void lee(int x,int y);
void afisare(int x,int y){
    ofstream g("brutar.out");
    int vf= 0;
    memset(v,0,sizeof(v));
    for(int i=5;i<7;i++){
        dx[i] = -dx[i];
        dy[i] = -dy[i];
    }
    g << a[x][y] << endl;
    v[++vf].x = x;
    v[vf].y = y;
    while(x>1){   
        for(int i=1;i<7;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(a[newX][newY]==a[x][y]-1){
                x = newX;
                y = newY;
                v[++vf].x = x;
                v[vf].y = y;
                break;
            }

        }
        // break;
    }
    while(vf){
        g << v[vf].x << ' ' << v[vf].y << endl;
        vf--;
    }
    g.close();
}

int main(){
    read();
    bordare();
    for(int i=1;i<=m;i++)
        if(!a[1][i]){
            lee(1,i);
            
        }
    int minim = 10000000,poz;
    for(int i=1;i<=m;i++)
        if(minim>a[n][i] && a[n][i]>0){
            minim = a[n][i];
            poz = i;
        }
    afisare(n,poz);
    return 0;
}

void read(){
    ifstream f("brutar.in");
    f >> n >> m;
    char c[NMax];
    f.getline(c,1);
    for(int i=1;i<=n;i++){
        f.getline(c,1001);
        for(int j=1;j<=m;j++)
            if(c[j-1]=='X')
                a[i][j]= -1;
            else if(c[j-1]=='O')
                a[i][j] = 0;
    }
    char special[100];
    f.getline(special,100);
    append_vector(special);
    f.getline(special,100);
    append_vector(special);
    f.close();
}
void append_vector(char c[]){
    int start = 0;
    for(int i=0;i<strlen(c);i++){
        if(strchr("NSEV",c[i])){
            int nd=0;
            for(int j=start;j<i;j++)
                if(c[j]>='0' && c[j]<='9')
                    nd = nd*10+c[j]-'0';
                else start++;
            start=i+1;
            if(c[i]=='N')
                dx[poz] = -nd;
            else if(c[i]=='S')
                dx[poz] = nd;
            else if(c[i]=='E')
                dy[poz] = nd;
            else if(c[i]=='V')
                dy[poz] = -nd;
        }
    }
    poz++;
}
void bordare(){
    for(int i=0;i<=n+1;i++)
        a[i][0] = a[i][m+1] = -1;
    for(int i=0;i<=m+1;i++)
        a[0][i] = a[n+1][i] = -1;
}

void lee(int x,int y){
    int prim,ultim;
    prim = ultim = 1;
    v[prim].x = x;
    v[prim].y = y;
    a[x][y] = 1;
    while(prim<=ultim && v[prim].x!=n){
        for(int i=1;i<poz;i++)
            if(!a[v[prim].x+dx[i]][v[prim].y+dy[i]]){
                ultim++;
                v[ultim].x = v[prim].x+dx[i];
                v[ultim].y = v[prim].y+dy[i];
                a[v[ultim].x][v[ultim].y] = a[v[prim].x][v[prim].y]+1;
            }
        prim++;
    }
    b.x = v[prim].x;
    b.y = v[prim].y;
}