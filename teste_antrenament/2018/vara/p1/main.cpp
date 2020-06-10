#include <iostream>
using namespace std;

int main(){
    int n,x,y,r,nr=0;
    cin >> n >> x >> y >> r;
    for(int i=1;i<=n;i++)
        if(i%x==r && i%y==r)
            nr++;
    cout << nr;

    cout << endl;
    return 0;
}