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
    
    int i=n,j=m,k=0;
    while(i>=1 && j>=1){
        if(a[i]<b[j]) {
            if(b[j]%2==0)
                ic[++k]=b[j--];
            else j--;
        }
        else if(b[j]<a[i]) {
            if(a[i]%2==0)
                ic[++k]=a[i--];
            else i--;        
        }
        else {
            if(a[i]%2==0 && b[j]%2==0){
                ic[++k]=a[i--]; ic[++k]=b[j--];}
            else {i--;j--;}
        }
    }
    while(i>=1)if(a[i]%2==0)ic[++k]=a[i--];else i--;
    while(j>=1)if(b[j]%2==0)ic[++k]=b[j--];else j--;
    for(int i=1;i<=k;i++)
            cout << ic[i] << ' ';
    cout << endl;
    return 0;
}