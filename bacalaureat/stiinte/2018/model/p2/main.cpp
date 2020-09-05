#include <iostream>
#include <cstring>
using namespace std;

void alta_solutie(){
    int n, v[200]={0};
    for(int i=1;i<=200;i++){
        v[i]=2;
        if(i%4==0)
            v[i]=1;
    }
    cin >> n;
    for(int i=1;i<n*4;i++)
        cout << v[i] << ' ';
}

int main(){
    // alta_solutie();
    int n,v[200]={0},x=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        v[x]=2;
        v[x+1]=2;
        v[x+2]=2;
        x+=3;
        if(i!=n)
            v[x++]=1;
    }
    for(int i=1;i<x;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}