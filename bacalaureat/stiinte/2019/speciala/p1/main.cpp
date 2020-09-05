#include <iostream>
#include <fstream> 
using namespace std;

int main(){
    int n,cimp=0,ok=0;
    cin >> n;
    while(n){
        int cif = n%10;
        if(cif%2==1 && cimp==0)
            cimp = cif;
        if(cif%2==1 && cimp)
            if(cimp!=cif)
                ok=1;
        n/=10;
    }
    if(!ok)
        cout << 1;
    else cout << 0;
    cout << endl;
    return 0;
}