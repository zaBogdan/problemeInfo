#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[100],x;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f >> x;
    x=x%2;//salvez paritatea
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(v[i]%2!=x && v[j]%2==x){
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }

    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}