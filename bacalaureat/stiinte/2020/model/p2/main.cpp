#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,x;
    f >> n >> x;
    int v[n+5];
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<n;i++)
        if(v[i]<x)
            for(int j=i+1;j<=n;j++)
                if(v[j]>=x){
                    int aux = v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}