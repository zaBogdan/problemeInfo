#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[51]={0}; 
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(v[i]!=0 && v[j]!=0)
                if(v[i]<=v[j]){
                    int aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}