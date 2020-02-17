#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[100];

int main(){
    int n,max=0,x;
    f >> n;
    for(int i=0;i<n;i++){
        f >> x;
        fr[x]++;
        max = x>max ? x : max;
    }
    for(int i=0;i<=max;i++)
        if(fr[i]==1)
            cout << i << ' ';
    cout << endl;
    return 0;
}