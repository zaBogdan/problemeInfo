#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n, v[30];
    bool pair;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<=n/2;i++)
        if(v[i]+v[n-i+1]==1){
            cout << v[i] << ' ' << v[n-i+1] << ' ' <<  i << ' ' << n-i+1 << endl;
            pair=true;
        }
    if(pair)
        cout << "DA";
    else cout << "NU";
    cout << endl;   
    return 0;
}   