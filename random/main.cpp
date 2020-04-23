#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n;
    k=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            cout << i + j << endl;
            k++;
        }
    cout << k;
    cout << endl;
    return 0;
}