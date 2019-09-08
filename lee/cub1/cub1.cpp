#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 105;
struct coord{int x,y,k;} c[100001];
struct initi{int a[NMax][NMax];}v[NMax],v2[NMax];
int dk[] = {1,-1,0,0,0,0};
int dx[] = {0,0,1,0,-1,0};
int dy[] = {0,0,0,1,0,-1};
int t,n,fr[7];
// int b[1000][NMax];

void read();
bool valid(int x,int y,int k);
void to_binary(int nr,int fr[]);
int is_access(int k,int x,int y,int fr[]);
void lee(){
    int prim,ultim;
    prim = ultim = 1;
    c[prim].x = 1;
    c[prim].y = 1;
    c[prim].k = 1;
    // b[1][1] = 1;
    v2[1].a[1][1] =1;
    while(prim<=ultim){
        memset(fr,0,sizeof(fr));
        to_binary(v[c[prim].k].a[c[prim].x][c[prim].y],fr);
        for(int i=0;i<6;i++){
            if(fr[i]){
                int newX = c[prim].x+dx[i];
                int newY = c[prim].y+dy[i];
                int newK = c[prim].k+dk[i];
                if(valid(newX,newY,newK) && !v2[newK].a[newX][newY]){
                    ultim++;
                    c[ultim].k = newK;
                    c[ultim].x = newX;
                    c[ultim].y = newY;
                    v2[newK].a[newX][newY] = v2[c[prim].k].a[c[prim].x][c[prim].y]+1;
                    // b[newX+ n*(newK-1)][newY] = b[c[prim].x+ n*(c[prim].k-1)][c[prim].y]+1;
                }
            }
        }
        prim++;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << v2[k].a[i][j] << ' ';
        cout <<endl;
    }

    // for(int i=1;i<=n*n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout << b[i][j] << ' ';
    //     cout << endl;
    // }
}

int main(){
    read();
    ofstream g("cub1.out");
    if(t==1){
        int maxim=0,mk,mi,mj;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    memset(fr,0,sizeof(fr));
                    to_binary(v[k].a[i][j],fr);
                    int nr = is_access(k,i,j,fr);
                    if(maxim<nr){
                        maxim = nr;
                        mk = k;
                        mi = i;
                        mj = j;
                    }
                }
            g << mk << ' ' << mi << ' ' << mj;
    }else{
        lee();
        g << v2[n].a[n][n];
        // g << b[n*n][n];
    }
    g.close();
    return 0;
}

void read(){
    ifstream f("cub1.in");
    f >> t >> n;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f >> v[k].a[i][j];
    }
    f.close();
}
void to_binary(int nr,int fr[]){
    int i=0;
    while(nr){
        fr[i++] = nr%2;
        nr/=2;
    }
}
bool valid(int x,int y,int k){
    if(x<1 || y<1 || k<1)
        return 0;
    if(x>n || y>n || k>n)
        return 0;
    return 1;
}
int is_access(int k,int x,int y,int fr[]){
    int nr=0;
    for(int i=0;i<6;i++)
        if(fr[i]){
            int newX = x+dx[i];
            int newY = y+dy[i];
            int newK = k+dk[i];
            if(valid(newX,newY,newK)){
                nr++;
            }
        }
    return nr;
}
