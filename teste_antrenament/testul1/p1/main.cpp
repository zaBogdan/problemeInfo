#include <iostream>
using namespace std;

int main(){
    int n;
    int d=2,p=0,maxp=0,maxd=2;
    cin >> n;   
    while(n && d<n){
        p=0;
        while(n%d==0){
            n=n/d;
            p++;
        }
        if(maxp<=p){
            maxp=p;
            maxd=d;
        }
        d++;
    }
    cout << maxd << ' ' << maxp;
    cout << endl;   
    return 0;
}