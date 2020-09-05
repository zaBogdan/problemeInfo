#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int n,x,max=0;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        fr[x]++;
        max = x>max ? x : max;
    }
    cout << max << ' ' << fr[max] << endl;
    return 0;
}