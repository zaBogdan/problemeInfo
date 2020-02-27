#include <iostream>
#include <fstream>
using namespace std;
ofstream g("sir.out");

int main()
{
    int x,k,s=1;
    cin >> k;
    x=1;
    while(s<k)
        x++,
        s= x*(x+1)/2;
    g << x-(s-k);
    return 0;
}
