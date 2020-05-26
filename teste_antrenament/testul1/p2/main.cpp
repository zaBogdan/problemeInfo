#include <iostream>
using namespace std;

int main(){
    short n,k,v[50]={0};
    cin >> n >> k;
    short ck = k;
    for(int i=1;i<=k*n;i++){
        v[i]=ck;
        if(i%k==0)
            ck++;
    }
    for(int i=1;i<=k*n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}