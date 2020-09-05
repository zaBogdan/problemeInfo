#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[21];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    int ok=true, par=false;
    for(int i=1;i<=n;i++){
        if(v[i]%2==1 && v[i]!=2015)
            ok=false;
        if(v[i]%2==0)
            par=true;
    }
    if(ok && par)
        cout << "DA";
    else cout << "NU";
    
    cout << endl;
    return 0;
}