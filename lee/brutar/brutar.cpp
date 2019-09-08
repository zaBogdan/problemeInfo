#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax=1001;
struct coord{int x,y;} v[1000001],final;
int n,m,poz=5,minim=100000,a[NMax][NMax],b[NMax][NMax],c[NMax][NMax],nr;
int dx[8] = {0, -1, 0, 1, 0};
int dy[8] = {0,  0, 1, 0,-1};
void read();

void append_vector(char c[]);
void copy_matrix();
bool ok(int i,int j);
int lee(int x,int y);
void print(){
    ofstream g("brutar.out");
    g << nr << endl;
    for(int i=5;i<=6;i++)
        dx[i] = -dx[i],
        dy[i] = -dy[i];
    memset(v,0,sizeof(v));
    int vf =0;
    v[++vf] = final;
    while(c[v[vf].x][v[vf].y]>1){
        for(int k=1;k<=6;k++){
            int newX = v[vf].x+dx[k];
            int newY = v[vf].y+dy[k];
            if(ok(newX,newY) && c[newX][newY]==c[v[vf].x][v[vf].y]-1){
                v[++vf].x = newX;
                v[vf].y = newY;
                k=10;
            }
        }
    }
    while(vf){
        g << v[vf].x << ' ' << v[vf].y << endl;
        vf--;
    }
    g.close();

}


int main(){
    read();
    for(int i=1;i<=m;i++)
        if(!a[1][i])
            nr = lee(1,i);
    print();
    return 0;
}

void read(){
    ifstream f("brutar.in");
    f >> n >> m;
    char c[NMax];
    f.getline(c,1);
    for(int i=1;i<=n;i++){
        f.getline(c,NMax);
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
bool ok(int i,int j){
    if(i<0 || j <0)
        return 0;
    if(i>n || j > m)
        return 0;
    return 1;
}
int lee(int x,int y){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            b[i][j] = a[i][j];

    int prim,ultim;
    memset(v,0,sizeof(v));
    prim = ultim =1;
    v[prim].x = x;
    v[prim].y = y;
    b[x][y] = 1;
    while(prim<=ultim || v[prim].x==n){
        for(int k=1;k<=6;k++){
            int newX = v[prim].x+dx[k];
            int newY = v[prim].y+dy[k];
            if(ok(newX,newY) && !b[newX][newY]){
                ultim++;
                v[ultim].x = newX;
                v[ultim].y = newY;
                b[newX][newY] = b[v[prim].x][v[prim].y]+1;
            }
        }
        prim++;
    }
    for(int i=1;i<=m;i++)
        if(b[n][i]<minim && b[n][i]>0){
            minim = b[n][i];
            final.x = n;
            final.y = i;
            copy_matrix();
        }
    return minim;
}
void copy_matrix(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j] = b[i][j];
}