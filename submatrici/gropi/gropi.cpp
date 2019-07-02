#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 1005;
int n,m,x,y;
bool a[NMax][NMax];
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};
char letter[10][10] = {"Blank","N","NE","E","SE","S","SV","V","NV"};

void read();
bool valid(int i,int j){
    if(i<1 || i>n)
        return false;
    if(j<1 || j>m)
        return false;
    return true;
}
int trees(int dir){
    int i=x,j=y,nr=0;
    while(valid(i+dx[dir],j+dy[dir])){
        i+=dx[dir];
        j+=dy[dir];
        if(!a[i][j])
            nr++;
    }
    return nr;
}

int main(){
    read();
    int maxim = 0,direction = 1;
    for(int i=1;i<=8;i++){
        int nr = trees(i);
        // cout << letter[i] <<' '  << nr << endl;
        if(maxim<=nr){
            maxim = nr; 
            direction = i;
        }
    }
    ofstream g("gropi.out");
    g << letter[direction] << ' ' << maxim; 
    g.close();
    return 0;
}
void read(){
    ifstream f("gropi.in");
    f >> n >> m >> x >> y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            double x;
            f >> x;
            a[i][j] =  x ? 1 : 0;
        }
    f.close();
}


