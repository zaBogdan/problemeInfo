#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,x, v[101],ok=0;
    f >> n;
    for(int i=0;i<n;i++)
        f >> v[i];
    f >> x;
    for(int i=1;i<n;i+=2)
        if(v[i]==x)
            ok=1;

    if(ok)
        cout << "DA";
    else cout << "NU";

    cout << endl;
    return 0;
}