#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
int fr[501];

int main(){
    int x,max=0;
    while(f >> x){
        fr[x]++;
        max = x>max ? x : max;
    }
    for(int i=1;i<=max;i++)
        if(fr[i]==1)
            cout << i << ' ';  
    cout << endl; //development purpose.
    return 0;
}