#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int n,x;
    f >> n;
    for(int i=0;i<=n;i++){
        f >> x;
        while(x){
            fr[x%10]=1;
            x/=10;
        }
    }
    for(int i=0;i<=9;i++)
        if(fr[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}