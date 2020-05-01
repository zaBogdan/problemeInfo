#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main()
{
    // introducerea de date
    const int n=7, m=7;
    int a[10][10];
    for(int i=1;i<=n;i++)
        for(int p=1;p<=m;p++)
            f >> a[i][p];
    // am doar a,i,p ( rezolvare )
    for(int i=2;i<=n;i++)
        for(int p=2;p<=m;p++)
            if(i==p)
                a[i][p] = a[i][p]*a[i-1][p-1];
    for(int i=n;i>=1;i--)
        cout << a[i][i] << ' ';
    cout << endl;
}