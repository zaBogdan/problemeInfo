#include <iostream>
using namespace std;

int main(){
    short n,k,v[25]={0};
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        if(i<=k)
            v[i]=k-i;
        else if(i>k)
            v[i]=i-k;
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;   
    return 0;
}