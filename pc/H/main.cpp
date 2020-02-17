#include <iostream>
#include <fstream>
using namespace std;
int a[505][505];
int x0,y0,k,n;
int dx[] = {-1,0,1,0}, dy[] = {0,1,-1,0}; //ULDR


void check_action(int x,int y);
int check_sorrounding(int x,int y);
void read(int n,int &x, int &y);
void border();
void move(int x, int y){
    k++;
    check_action(x,y);
    int dir = check_sorrounding(x,y);
    move(x+dx[dir],y+dy[dir]);
    if(k==10)
        return;
}

int main(){
    int x,y;
    read(n,x,y);
    cout << x << ' ' << y;
    border();
    //move(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

void read(int n,int &x, int &y){
    ifstream f("file.in");
    f >> n >> x >> y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
             f >> a[i][j];
    f.close();
}

void check_action(int x,int y){
    if(a[x][y]==0){
        a[x][y]=1;
    }else if(a[x][y]==1)
        a[x][y]=2;
}
void border(){
    for(int i=0;i<=n;i++){
        a[0][i]=a[n+1][i]=-1;
        a[i][0]=a[i][n+1]=-1;
    }
}
int check_sorrounding(int x,int y){
    //cazul favorabil
    for(int i=0;i<4;i++)
        if(a[x+dx[i]][y+dy[i]]==1)
            return i;
    //caz nefavorabil 
    for(int i=0;i<4;i++)
        if(a[x+dx[i]][y+dy[i]]!=-1)
            return i;
    return 0;
}