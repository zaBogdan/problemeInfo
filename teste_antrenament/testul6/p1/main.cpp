#include <iostream> 
using namespace std;

int main(){
    int n,d=2,p=1;
    cin >> n;
    while(n!=1){
        bool ok=false;
        while(n%d==0){
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