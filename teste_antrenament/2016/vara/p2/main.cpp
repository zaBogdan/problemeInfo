#include <iostream>
using namespace std;

int main(){
    int n,v[101]={0};
    cin >> n;
    for(int i=1;i<=n;i++)
        if(i%2==0)
            v[i]=i;
        else
            v[i]=v[i-1]+v[i-2];
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';

    cout << endl;
    return 0;
}