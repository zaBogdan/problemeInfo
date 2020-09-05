#include <iostream>
using namespace std;
int a[10][10];

int main(){
    int n,k;
    // cin >> n >> k;
    n=3,k=4;
    // int a[n+1][k+1];
    for(int i=1;i<=k;i++){
        a[1][i] = i;
    }
    for(int i=1;i<=k;i++){
        for(int j=2;j<=n*k;j++){
            a[j][i] = a[n*(j/k)+1][i];
            if(j%k==0)
                a[j][i]=a[n*(j/k-1)+1][i]+1;
        }
    }
    for(int i=1;i<=n*k;i++){
        for(int j=1;j<=k;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}