#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n,x,v[51];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f >> x;
    for(int i=1;i<=n;i++)
        if(v[i]%2==0)
            v[i]=v[i]-x;
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}