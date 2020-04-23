#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");


int main(){
    int n,x,nr=0;
    f >> n;
    int v[n+2];
    for(int i=0;i<n;i++){
        f>> x;
        if(x%2==0)
            cout << x << ' ';
        else
            v[++nr]=x;
    }
    for(int i=nr;i>0;i--)
        cout << v[i] << ' ';
    cout << endl; //development purpose
    return 0;
}