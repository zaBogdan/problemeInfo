#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[50];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<n;i++){
        if(v[i]%2==v[i+1]%2){
            n++;
            for(int j=n;j>i+1;j--)
                v[j]=v[j-1];
            v[i+1]=2020;
            i++;
        }
    }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}