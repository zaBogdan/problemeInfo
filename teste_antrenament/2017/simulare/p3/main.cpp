#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.in");

int main(){
    int n,m,a[1000],b[1000],ic[2000];
    f >> n >> m;
    for(int i=1;i<=n;i++)
        f >> a[i];
    for(int j=1;j<=m;j++)
        f >> b[j];
    
    int i=1,j=1,k=0;
    while(i<=n && j<=m){
        if(a[i]<b[i]) ic[++k]=a[i++];
        else if(b[j]>a[i]) ic[++k]=b[j++];
        else {ic[++k]=a[i++]; ic[++k]=b[j++];}
    }
    while(i<=n)ic[++k]=a[i++];
    while(j<=m)ic[++k]=b[j++];
    for(int i=1;i<=k;i++)
        // if(ic[i]%2==0)
            cout << ic[i] << ' ';
    cout << endl;
    return 0;
}