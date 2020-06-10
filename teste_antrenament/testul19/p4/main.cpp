#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int m,n,k;
    short a[25][25]={0};
    bool ok = false;
    f >> m >> n >> k;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            f >> a[i][j];
    for(int i=0;i<m;i++){
       bool is_complementar = true;
        for(int j=0;j<n;j++)
                if(a[i][j]+a[i+k][j]!=1)
                    is_complementar = false; 
        if(is_complementar)
            ok = true;
    }
    if(ok)
        cout << "DA";
    else cout << "NU";
    cout << endl;   
    return 0;
}   