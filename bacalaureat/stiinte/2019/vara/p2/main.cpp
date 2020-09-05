#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n , v[30],ok=1;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<=n/2 &&ok;i++)
        if(v[i]!=v[n-i+1])
            ok=0;
    if(ok)
        cout << "DA";
    else cout << "NU";
    cout << endl;
    return 0;
}