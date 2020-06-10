#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int n,v[10]={0};
    while(f >> n){
        while(n){
            v[n%10]++;
            n/=10;
        }
    }
    for(int i=0;i<=9;i++)
        if(v[i]==1)
            cout << i << ' ';
    cout << endl;
    return 0;
}