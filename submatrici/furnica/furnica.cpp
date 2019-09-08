#include <iostream>
#include <fstream>
using namespace std;
ifstream f("furnica.in");
ofstream g("furnica.out");
const int NMax = 120;
int n,k,a[NMax][NMax],viz[NMax][NMax];
int new_x = 1, new_y = 1,s=0,nr=0,maxim=0;
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void generate_matrix();
void read(); 
void visits();

int main(){
    read();
    for(int i=1;i<=k;i++){
        int x;
        f >> x;
        visits(); 
        s+=a[new_x][new_y];
        a[new_x][new_y]=0;
        new_x += dx[x];
        new_y += dy[x];
    }
    s+=a[new_x][new_y];
    
    g << s << ' ' << nr << endl;

    f.close();
    g.close();
    return 0;
}

void read(){
    f >> n >> k;
    generate_matrix();
}
void generate_matrix(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=(i+j)%6;
}
void visits(){
    viz[new_x][new_y]++;
    if(maxim<viz[new_x][new_y]){
        maxim = viz[new_x][new_y];
        nr = 1;
    }else if(maxim == viz[new_x][new_y])
        nr++;
}