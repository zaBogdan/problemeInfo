#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[65]={0};
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    v[0]=1;
    for(int i=1;i<=n;i++)
        if(i%2==0){
            for(int j=n+1;j>=i;j--)
                v[j]=v[j-1];
            v[i]=v[i-1]+v[i+1];
            i++;n++;
        }
    for(int i=0;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}