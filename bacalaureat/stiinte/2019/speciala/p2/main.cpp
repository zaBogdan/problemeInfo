#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n, v[100]={0},max=-1,ok=0;
    f >> n;
    for(int i=1;i<=n;i++){
        int x;
        f >> x;
        v[x]++;
        if(max<x)
            max=x;
    }
    for(int i=0;i<=max;i++){
        for(int j=0;j<v[i];j++)
            cout << i << ' ';
        if(i>9 && !ok){
            cout << endl;
            ok=1;
        }
    }
    cout << endl;
    return 0;
}