#include <iostream>
#include <fstream>
using namespace std;
ifstream f("comparatori.in");
const int NMax = 100;


bool func(int n, int m, int r[NMax][2],int a[NMax]){
    for(int i=1;i<=m;i++)
        if(a[r[i][1]]>a[r[i][2]])
            swap(a[r[i][1]],a[r[i][2]]);
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])
            return 0;
    return 1;
}


int main(){
    int n,m,r[NMax][2],a[NMax];
    f >> n >> m;
    for(int i=1;i<=m;i++)
        f >> r[i][1] >> r[i][2];
    for(int i=1;i<=n;i++)
        f >> a[i];
    cout << func(n,m,r,a);
    cout << endl;
    for(int i=1;i<=n;i++)
        cout << a[i] << ' ';
    cout << endl;
}