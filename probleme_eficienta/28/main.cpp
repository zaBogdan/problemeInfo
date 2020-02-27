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
        max = fr[x]>max ? fr[x] : max;
        maxnr = x > maxnr ? x : maxnr;
    }
    for(int i=0;i<=maxnr;i++)
        if(fr[i]==max)
                cout << i << ' ' ;
    cout << endl; //development purpose.
    return 0;
}