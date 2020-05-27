#include <iostream> 
using namespace std;

int main(){
    int n,d=2,p=1;
    cin >> n;
    while(n && d<n){
        bool ok=false;
        while(n%d==0){
            cout << n << endl;
            n/=d;
            ok=true;
        }
        if(ok)
            p*=d;
        d++;
    }
    cout << p;
    cout << endl;
    return 0;
}