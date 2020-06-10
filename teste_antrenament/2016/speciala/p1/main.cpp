#include <iostream>
using namespace std;

int main(){
    int n,d=2,p=1;
    cin >> n;
    while(n!=1){
        int ok=0;
        while(n%d==0){
            ok=1;
            n/=d;
        }
        if(ok)
            p*=d;
        d++;
    }
    cout << p;
    cout << endl;
    return 0;
}