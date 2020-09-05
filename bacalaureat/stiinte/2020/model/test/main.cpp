#include <iostream>
using namespace std;

int main(){
    int m,n,x;
    int s=0,pm=1,pn=1;
    cin >> m >> n >> x;
    do{
        if(m%x==0){
            s+=m;
            pm=x;
        }
        if(n%x==0 && m!=n){
            s+=n;
            pn=x;
        }
        m+=pm;
        n-=pn;
    }while(m<=n);
    cout << s;
    cout << endl;
    return 0;
}