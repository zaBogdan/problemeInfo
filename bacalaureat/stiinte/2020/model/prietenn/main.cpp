#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("numere.in");

int main(){
    int min=101, max=0, fr[101]={0};
    int x;
    while(f >> x){
        fr[x]=1;
        if(min>x)
            min=x;
        if(max<x)
            max=x;
    }
    int lungime=0,lmax=0;
    for(int i=min;i<max;i++){
        if(fr[i]){
            for(int j=i+1;j<=max;j++)
                if(!fr[j+1]){
                    lungime = j-i+1;
                    if(lmax<lungime)
                        lmax = lungime;
                    i=j;
                    j=max+10;
                    lungime=0;
                }
        }
    }
    cout << lmax;
    cout << endl;
    return 0;
}