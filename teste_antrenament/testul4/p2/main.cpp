#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    short n, v[30];
    f >> n;
    for(int i=0;i<n;i++)
        f >> v[i];
    int nr=0;
    for(int i=0;i<n/2;i++){
        if(v[i]+v[n-i-1]==1){
            cout << v[i] << ' ' << v[n-i-1] << ' ' << i << ' ' << n-i-1 << endl;
            nr++;
        }
    }
    cout << nr;
    cout << endl;   
    return 0;
}