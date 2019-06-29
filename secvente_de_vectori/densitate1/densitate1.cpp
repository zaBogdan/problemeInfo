#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 100001;
int n,par[NMax],impar[NMax],poz_p,poz_ip;
double ratio;

int crc(int a,int b){
    if(!b)
        return a;
    return crc(b,a%b);
}

void density_calc(){
    int cmmdc = crc(ratio*100,100);
    cout << (ratio*100)/cmmdc << ' ' << 100/cmmdc << endl; 
}

void read(){
    ifstream f("densitate.in");
    f >> n;

    for(int i=1;i<=n;i++){
        int x;
        f >> x;
        if(x%2==0)
            par[poz_p++]=x;
        else impar[poz_ip++] = x;
    }
    f >> ratio;
    f.close();
}

int main(){
    read();
    density_calc();
    return 0;
}