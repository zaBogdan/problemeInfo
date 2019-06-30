#include <iostream>
#include <fstream>
using namespace std;
ofstream g("paint.out");
const int NMax = 250001;
int n,m,k,b[NMax],a[NMax];

void read();

int main(){
    read();
    int under=0;
    for(int i=0;i<n;i++){
        int nr=0;
        for(int j=1;j<=m;j++)
            if(a[j]<=i && i+1<=b[j])
                nr++;
            if(nr<k) under++;
        
    }
    g << under;
    g.close();
    return 0;
}

void read(){
    ifstream f("paint.in");
    f >> n >> k >> m;
    int nr=0,s=0;
    for(int i=1;i<=m;i++){
        int x, y;
        f >> x >> y;
        a[i]=x,b[i]=x+y;
    }
    f.close();
}