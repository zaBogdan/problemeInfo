#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n, v[21];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    int aux = v[n];
    for(int j=n-1;j>=1;j--)
        v[j+1]=v[j];
    v[1]=aux;
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}