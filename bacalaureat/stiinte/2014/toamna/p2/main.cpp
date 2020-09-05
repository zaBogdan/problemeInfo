#include <iostream>
using namespace std;

int main(){
    int n,v[1000];
    cin >> n;
    v[0]=0;
    for(int i=1;i<=n;i++){
        v[i]=v[i-1]+2;
        if(v[i]%5==0)
            v[i]+=2;
    }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}