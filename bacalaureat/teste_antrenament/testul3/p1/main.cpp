#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int d=2,nr=0;
    while(n && m && (d<=n && d<=m)){
        if(n%d==0 && m%d==0){
            nr++;
        }
        while(n%d==0)
            n/=d;
        while(m%d==0)
            m/=d;
        d++;
    }
    cout << nr;
    cout << endl;   
    return 0;
}