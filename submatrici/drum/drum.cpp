#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 600;
int n,m,vmax,a[NMax][NMax],x,y;
int dx[]={0,-1, 0, 1, 0}, dy[4]={0,0, 1, 0, -1} ;

void read();
void getpos(int nr){
    x = nr/n+1;
    y = nr%m;
    if(nr%n==0){
        x = nr/n,y=n;
    } 
}

int main(){
    read();
    
    return 0;
}

void read(){
    ifstream f("drum.in");
    f >> n >> m >> vmax;
    for(int i=1;i<=vmax;i++){
        int x;
        f >> x;
        for(int j=1;j<=x;j++){
            int nr;
            f >> nr;
            getpos(nr);
            bool ok1=0, ok2=0;
            a[x][y]=3;
            for(int k=1;k<=4;k++){
                if(a[x+dx[k]][y+dy[k]]==1) ok1=1,a[x][y]=1;

            }
        }
    }
    f.close();
}