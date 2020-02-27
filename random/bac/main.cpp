#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    if(m%3==n)
        cout << (m+n)*n;
    else cout << 0;
    cout << endl;
    return 0;
}