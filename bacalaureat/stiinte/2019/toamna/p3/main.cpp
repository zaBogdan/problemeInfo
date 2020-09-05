#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int fr[1000]={0};
    int x,max=0;
    while(f >> x)
        if(x%2==0){
            fr[x]++;
            if(max<x)
                max=x;
        }
    for(int i=0;i<=max;i+=2)
        for(int j=0;j<fr[i];j++)
            cout << i << ' ';
    cout << endl;
    return 0;
}