#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[1000];
    cin >> n;
    //determin limita superioara
    int first=1,poz=1;
    while(poz<n){
        first+=2;
        if(first%3==0)
            first+=2;
        poz++;
    }
    v[1]=first;
    for(int i=2;i<=n;i++){
        v[i]=v[i-1]-2;
        if(v[i]%3==0)
            v[i]-=2;
    }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}