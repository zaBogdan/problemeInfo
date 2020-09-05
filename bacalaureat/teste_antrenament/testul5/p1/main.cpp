#include <iostream>
using namespace std;

int main(){
    int n,maxnr=0;
    cin >> n;
    while(n){
        short cif=n%10;
        // maxnr = maxnr<cif ? cif : maxnr;
        if(maxnr<cif) maxnr=cif;
        n/=10;
    }
    cout << maxnr+1;
    cout << endl;   
    return 0;
}