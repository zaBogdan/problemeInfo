#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int n,x;
    f >> n;
    for(int i=0;i<n;i++){
        f >> x;
        fr[x]++;
    }
    for(int i=9;i>=0;i--)
        for(int j=1;j<=fr[i];j++)
            cout << i;
    cout <<endl;
    return 0;
}