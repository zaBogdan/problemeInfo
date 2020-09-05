#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n,k, v[24]={0};
    f >> n >> k;
    for(int i=1;i<=n;i++)
        f >> v[i];
    int aux;
    aux=v[1];
    for(int i=1;i<k;i++){
        v[i] = v[i+1]; 
    }
    v[k]=aux;
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}