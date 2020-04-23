#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere.in");

int main(){
    int n,m;
    int v1[100],v2[100];
    f >> n >>m;
    for(int i=1;i<=n;i++)
        f >>v1[i];
    for(int j=1;j<=m;j++)
        f >> v2[j];

    int i=1,j=1,s=0,working=1;
    while(i<=n && j<=m && working){
        while(s<v2[j]){
            s+=v1[i];
            i++;
        }
        if(s==v2[j]){
            j++;
        }else working=0;
        s=0;
    }
    if(working)
        cout << "Da";
    else cout << "Nu";
    cout << endl; //development purpose.
    return 0;
} 