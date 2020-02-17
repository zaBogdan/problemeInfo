#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


unsigned int gcd (unsigned int n1, unsigned int n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

int main(){
    int n,k;
    cin >> n >> k;
    bool viz[n];
    int v[n];
    memset(viz, 0, n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/2 && i*j<=n;j++)
            if(gcd(j*i,i)>1){
                v[i]=i*j;
                viz[i*j]=true;
            }
    }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}