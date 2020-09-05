#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
int fr[101];

int main(){
    int n, x, max=0, maxnr=0;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        fr[x]++;
        maxnr = x > maxnr ? x : maxnr;
    }
    for(int i=maxnr;i>=0;i--)
        if(fr[i])
                cout << i << ' ' << fr[i] << endl;
    cout << endl; //development purpose.
    return 0;
}