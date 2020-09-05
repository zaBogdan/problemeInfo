#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n;
    float v[52],sum=0;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> v[i];
        sum+=v[i];
    }
    sum /=n;
    for(int i=n;i>=n/2;i--){
        v[i+1]=v[i];
    }
    v[n/2+1]=sum;
    for(int i=1;i<=n+1;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}