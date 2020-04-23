#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int v[100];

int main(){
    int n, x,max=-10001;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        max = x>max ? x : max;
        cout << max << ' ';
    }
    cout << endl; //development purpose.
    return 0;
} 