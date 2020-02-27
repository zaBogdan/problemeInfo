#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
int fr[100];

int main(){
    int k, x,max=0;
    while(f >> x){
        fr[x]++;
        max = x>max ? x : max; 
    }
    cin >> k;
    for(int i=max;i>k;i--)
        if(fr[i])
            cout << i << ' ';
    cout << endl; //development purpose.
    return 0;
}