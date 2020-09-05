#include <iostream> 
using namespace std;

int main(){
    int n, d=2,s=0;
    cin >> n;
    while(n && d<=n){
        bool ok=false;
        while(n%d==0){
            n/=d;
            ok=true;
        }
        if(ok)
            s+=d;
        d++;
    }
    cout << s;
    cout << endl;
    return 0;
}