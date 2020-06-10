#include <iostream>
using namespace std;

int main(){
    int n,prim=0;
    cin >> n;
    int is_n_prim=1,cn=n;
    // int d=2;
    // while(d<n){
    //     if(n%d==0)
    //         is_n_prim=0;
    //     d++;
    // }
    prim=0;
    while(!prim){
        int d=2,hope=1;
        while(d<n && hope){
            if(n%d==0)
                hope=0;
            d++;
        }
        if(cn==n && !hope)
            is_n_prim=0;
        if(hope && cn!=n)
            prim=n;
        n++;
    }
    if(is_n_prim)
        cout << prim-1;
    else
        cout << prim+1;
    cout << endl;
    return 0;
}