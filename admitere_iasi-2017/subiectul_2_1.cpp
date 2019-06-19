#include <iostream>
#include <cmath>
using namespace std;
int a[150][150];

int f(int u,int v, int t){
    int m = (u+v)/2;
    if(u>=v) return u;
    if(m*m>t) return f(u,m-1,t);
    if(m*m<t) return f(m+1,v,t);
    return m;
}

int main(){

    cout << f(0,63,64);

}