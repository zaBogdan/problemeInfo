#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 400;
int n,a[NMax][NMax];
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void read();
bool valid(int i,int j);
int sum(int x,int y,int dir){
    int s = 0;
    while(valid(x+dx[dir],y+dy[dir])){
        x+=dx[dir],y+=dy[dir];
        s+=a[x][y];
    }
    return s;
}

int main(){
    read();
    int maxim = 0,px=1,py=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int s=0;
            for(int k=1;k<=8;k++)
                s+=sum(i,j,k);
            s+=a[i][j];
            if(maxim < s){
                px = i;
                py = j;
                maxim = s;
            }
        }
    ofstream g("suma7.out");
    g << maxim << endl;
    g << px << ' ' << py << endl;
    g.close();
    return 0;
}

void read(){
    ifstream f("suma7.in");
    f >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f >> a[i][j];
    f.close();
}
bool valid(int i,int j){
    if(i<1 || i>n)
        return false;
    if(j<1 || j>n)
        return false;
    return true;
}