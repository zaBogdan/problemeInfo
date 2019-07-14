#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 500;
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};
int t,n,m,a[NMax][NMax],aF[NMax][NMax],nr_zone, d[1000000];
int maxim,maxi,maxj,maxc;

void read();
void fill(int i,int j);
bool ok(int x,int y);
void outsider(int x,int y){
    for(int k=1;k<=4;k++)
        for(int kk=1;kk<=4;kk++){
            int newX = x+dx[k],newY = y+dy[k];
            int newx = x+dx[kk],newy = y+dy[kk];
            if(ok(newX,newY) && ok(newx,newy))
                if(a[newX][newY]==a[newx][newy] && a[x][y]!=a[newX][newY] && k!=kk)
                    if(aF[newX][newY]!=aF[newx][newy])
                    {
                        int zone1 = d[aF[newX][newY]], zone2 = d[aF[newx][newy]];
                        if(maxim<zone1+zone2){
                            maxim = zone1+zone2;
                            maxi = x;
                            maxj = y;
                            maxc = a[newX][newY];
                        }
                    }
        }
}

int main(){
    read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!aF[i][j]){
                nr_zone++;
                fill(i,j);
            }
    ofstream g("ferma.out");
    if(t==1){
        int maxim = 0;
        for(int i=1;i<=nr_zone;i++)
            if(maxim<d[i])
                maxim = d[i];
        g << maxim << endl;
    }else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                outsider(i,j);
        g << maxi <<' ' << maxj;
        g << endl << (char) ('a'+maxc-1);
    }
    g.close();
    return 0;
}

void read(){
    ifstream f("ferma.in");
    f >> t >> n >> m;
    char c[500];
    f.getline(c,500);
    for(int i=1;i<=n;i++){
        f.getline(c,500);
        for(int j=1;j<=m;j++)
            a[i][j] = c[j-1]-'a'+1;
    }
    f.close();
}
void fill(int i,int j){
    aF[i][j] = nr_zone;
    d[nr_zone]++;
    for(int k=1;k<=4;k++){
        int newX = i+dx[k];
        int newY = j+dy[k];
        if(ok(newX,newY) && !aF[newX][newY] && a[i][j]==a[newX][newY])
            fill(newX,newY);
    }
}
bool ok(int x,int y){
    if(x<1 || y < 1)
        return 0;
    if(x>n || y > m)
        return 0;
    return 1;
}