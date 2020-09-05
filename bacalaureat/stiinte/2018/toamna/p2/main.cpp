#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[50];
    f >> n;
    for(int i=n;i>=1;i--)
        f >> v[i];
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';

    cout << endl;
    return 0;
}