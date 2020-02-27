#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
int fr[101];

int main(){
    int n, x, missing=0;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        fr[x]++;
    }
    for(int i=1;i<=100;i++)
        if(!fr[i]){
            missing = 1;
            cout << i << ' ' ;
        }
    if(!missing)
        cout << "NU LIPSESTE NICIUN NUMAR";
    cout << endl; //development purpose.
    return 0;
}