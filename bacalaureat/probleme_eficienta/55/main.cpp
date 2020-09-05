#include <iostream>
#include <fstream>
using namespace std;
ifstream f1("nr1.txt");
ifstream f2("nr2.txt");
int fr[1001];

int main(){
    int x,n;
    int min = 1001,max=-1001;
    f1 >> n;
    for(int i=1;i<=n;i++){
        f1 >> x;
        fr[x]++;
        min = x<min ? x : min;
        max = max<x ? x : max;
    }
    f2 >> n;
    for(int i=1;i<=n;i++){
        f2>>x;
        fr[x]++;
        min = x<min ? x : min;
        max = max<x ? x : max;    
    }
    for(int i=min;i<=max;i++)
        if(fr[i])
            cout  << i << ' ';
    cout << endl; //development purpose.
    return 0;
} 