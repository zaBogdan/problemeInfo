#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[1001];

int main(){
    int n,x,max=-1;
    f >> n;
    for(int i=0;i<n;i++){
        f >> x;
        fr[x]++;
        max = max < x ? x : max;
    }
    for(int i=0;i<=max;i++)
        for(int j=1;j<=fr[i];j++)
            cout << i << ' ';
    cout << endl;
    return 0;
}