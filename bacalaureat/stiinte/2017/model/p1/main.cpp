#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b,nr=0;
    cin >> a >> b;
    for(int i=a;i<=b;i++)
        if(floor(sqrt(i))*floor(sqrt(i)+1)==i)
            nr++;
    cout << nr;
    cout << endl;
    return 0;
}