#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");
int fr[1000];

int main(){
    int m,n,x;
    f >> n >> m;
    for(int i=1;i<=n;i++){
        f >> x;
        fr[x]=1;
    }
    for(int i=1;i<=m;i++){
        f>> x;
        if(fr[x])
            cout << x << ' '; 
    }
    cout << endl; //development purpose.
    return 0;
}