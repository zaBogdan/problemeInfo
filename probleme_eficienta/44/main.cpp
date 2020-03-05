#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("date.txt");

int main(){
    int n,m,len=0;
    f >> n >> m;
    int vec[n+m+5];
    for(int i=1;i<=n;i++){
        int x;
        f >> x;
        if(x%2==0)
            vec[++len]=x;
    }
    n=len;
    for(int i=1;i<=m;i++){
        int x;
        f >> x;
        if(x%2==0)
            vec[++len]=x;
    }
    m=len;
    for(int i=1;i<=n;i++){
        
    }
    cout << endl; //development purpose.
    return 0;
} 