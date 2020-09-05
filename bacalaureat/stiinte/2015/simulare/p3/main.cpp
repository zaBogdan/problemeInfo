#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int n, x, v[1001];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f >> x;
    int li=1,ls=n,gasit=0;
    while(li<=ls){
        int mij = (li+ls)/2;
        if(v[mij]<=x) gasit = 1;
        else if(v[mij]>)
    }
    cout << endl;
    return 0;
}