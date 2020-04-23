#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b){
    int c;
    while(b){
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    int n,m;
    ifstream f("daruri.in");
    f >> n >> m;
    int div = cmmdc(n,m);
    ofstream g("daruri.out");
    if(div>1)
        g << div << '\n' << n/div << ' '  << m/div;
    else g << 0 << '\n' << 0 << ' ' << 0;

    f.close();
    g.close();
    return 0;
}