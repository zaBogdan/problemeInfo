#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 205;
struct star{int v,sh;} a[NMax][NMax];
int n,m,poz,lenght[NMax];
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void read();
bool valid(int i,int j);
bool search_star(int i,int j);
void search_inline(int x,int y){
    poz=0;
    for(int i=x+1;i<=n;i++)
        if(a[i][y].sh){
            poz++;
            lenght[poz]=i-x;
        }
}
bool square(int i,int j,int lenght){
    if(valid(i+lenght,j+lenght))
    if(a[i+lenght][j].sh==1 && a[i][j+lenght].sh==1 && a[i+lenght][j+lenght].sh==1)
        return true;
    return false;
}

int main(){
    read();
    int nr_sh=0,maxim=0,squaress=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(search_star(i,j)){
                nr_sh++;
                a[i][j].sh = 1;
            }
    ofstream g("patrat2.out");
    g << nr_sh << endl;
    if(nr_sh)
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j].sh){
                search_inline(i,j);
                for(int k=1;k<=poz;k++)
                    if(square(i,j,lenght[k])){
                        if(maxim<lenght[k]+1)
                            maxim = lenght[k]+1;
                        squaress++;
                    }
            }
    g << squaress << endl << maxim;
    g.close();
    return 0;
}

void read(){
    ifstream f("patrat2.in");
    f >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f >> a[i][j].v;
    f.close();
}
bool valid(int i,int j){
    if(i<1 || i>n)
        return false;
    if(j<1 || j>m)
        return false;
    return true;
}
bool search_star(int i,int j){
    for(int k=1;k<=8;k++)
        if(valid(i+dx[k],j+dy[k]))
            if(a[i][j].v<=a[i+dx[k]][j+dy[k]].v){
                return false;
            }
    return true;
}