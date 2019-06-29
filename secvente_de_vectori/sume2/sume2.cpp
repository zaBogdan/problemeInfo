#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sume2.in");
ofstream g("sume2.out");
const int NMax = 100001; 
int n,v[NMax],s[NMax],k;

int main(){
    f >> n;    
    for(int i=1;i<=n;i++){
        f >> v[i];
        if(i==1)
            s[i]=v[i];
        else 
            s[i]=v[i]+s[i-1];
    }

    f >> k;
    for(int y=1;y<=k;y++){
        int i,j;
        f >> i >> j;
        g << s[j]-s[i-1] << endl;
    }
    f.close();
    g.close();
    return 0;
}