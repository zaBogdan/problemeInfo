#include <iostream>
using namespace std;

int main(){
    int n, v[51],x;
    cin >> n >> x;
    for(int i=1;i<=n;i++)
        v[i] = x+n-i;
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}