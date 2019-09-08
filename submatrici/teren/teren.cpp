#include <iostream>
#include <fstream>
using namespace std;
ofstream g("teren.out");
const int NMax = 200;
int p,n,m,t,r,c,a[NMax][NMax];

void read();
void create_submatrix(int ix,int iy,int fx,int fy);
int maximum_element();
int maximum_square(int i,int j);
bool check_square(int ix,int iy,int fx,int fy);
void number_of_squares(){
    int maxim = 0, nr = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j]){
                int area = maximum_square(i,j);
                if(maxim<area)
                    maxim = area;
                
            }
    g << maxim;
}

int main(){
    read();
    if (p==1) g << a[r][c];
    else if(p==2) g << maximum_element();
    else number_of_squares();
    g.close();
    return 0;
}

void read(){
    ifstream f("teren.in");
    f >> p;
    f >> n >> m >> t >> r >> c;
    for(int i=1;i<=t;i++){
        int ix,iy,fx,fy;
        f >> ix >> iy >> fx >> fy;
        create_submatrix(ix,iy,fx,fy);
    }
    f.close();
}
void create_submatrix(int ix,int iy,int fx,int fy){
    for(int i=ix;i<=fx;i++)
        for(int j=iy;j<=fy;j++)
            a[i][j]++;
}
int maximum_element(){
    int maxim = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(maxim<a[i][j]){
                maxim = a[i][j];
            }
    return maxim;
}
int maximum_square(int x,int y){
    bool ok = true;
    int area=1;
    for(int i=1;i<=n && ok;i++){
        if(x+i<=n && y+i<=m){
            int lengh_x = x+i-x+1;
            int lengh_y = y+i-y+1;
            if(lengh_x==lengh_y){
                ok = check_square(x,y,x+i,y+i);
                if(ok)
                    area = lengh_x*lengh_y;
            }
        }
        
    }
    return area;
}
bool check_square(int ix,int iy,int fx,int fy){
    for(int i=ix;i<=fx;i++)
        for(int j=iy;j<=fy;j++)
            if(a[i][j])
                return false;
    return true;
}