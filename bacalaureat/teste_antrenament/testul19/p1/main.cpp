#include <iostream>
using namespace std;

int main(){
    int n,nr=0;
    cin >> n;
    int paritate = n%2;
    for(int i=paritate;i<=n;i+=2)
        if(i && n%i==0)
            nr++;
    cout << nr;
    cout << endl;   
    return 0;
}   