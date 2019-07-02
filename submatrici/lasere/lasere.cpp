#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 205;
struct val{int v,g;} a[NMax][NMax];
int n,m,c,gropi,transee;
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void read();
bool valid(int i,int j);
void shoot(int i,int j,int d);
void afisare();
void search();
bool search_gropi(int i,int j);
int search_transee(){
    for(int i=1;i<=n;i++){
        int lenght = 0;
        for(int j=1;j<=n;j++)
            if(a[i][j].g==1) lenght++;
            else {
                if(lenght>=2) transee++;
                lenght=0;
            }
        if(lenght>=2) transee++;
    }
    return transee;
}

int main(){
    read();
    search();
    // afisare();
    ofstream g("lasere.out");
    if(c==1) g << gropi;
    else g << search_transee();
    g.close();

    return 0;
}

void read(){
    ifstream f("lasere.in");
    f >> c;
    f >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f >> a[i][j].v;

    for(int k=1;k<=m;k++){
        int i,j,d;
        f >> i >> j >> d;
        shoot(i,j,d);
    }
    f.close();
}
void shoot(int i,int j,int d){
    int dxx[] = {0, -1, 0, 1,  0};
    int dyy[] = {0,  0, 1, 0, -1};
    while(valid(i,j)){
        i+=dxx[d];
        j+=dyy[d];
        a[i][j].v--;
    }
}
bool valid(int i,int j){
    if(i<1 || i>n)
        return false;
    if(j<1 || j>n)
        return false;
    return true;
}
void afisare(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << a[i][j].g << ' ';
        cout << endl;
    }
}
void search(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(search_gropi(i,j)){
                gropi++;
                a[i][j].g = 1;
            }
        }
}
bool search_gropi(int i,int j){
    for(int k=1;k<=8;k++)
        if(valid(i+dx[k],j+dy[k]))
            if(a[i][j].v>a[i+dx[k]][j+dy[k]].v)
                return false;
    return true;
}