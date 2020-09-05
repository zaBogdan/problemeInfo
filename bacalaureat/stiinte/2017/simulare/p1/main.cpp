#include <iostream>
using namespace std;

int main(){
    int n,i=0,nr=0;
    cin >> n;
    while(n){
        if(n%10==i)
            nr++;
        i++;
        n/=10;
    }
    cout << nr;
    cout << endl;
    return 0;
}