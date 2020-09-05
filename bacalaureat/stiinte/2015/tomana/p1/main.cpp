#include <iostream>
using namespace std;

int main(){
    int n,nr=0;
    cin >> n;
    while(n){
        int c=n%10;
        if(c==2 || c==3 || c==5 || c==7)
            nr++;
        n/=10;
    }
    cout << nr;
    cout << endl;
    return 0;
}