#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");


void suma(int n, int s){
    int fr[10]={0};
    s=0;
    while(n){
        int c=n%10;
        if(!fr[c] && !(c%2)){
            s+=c;
        }
        fr[c]=1;
        n/=10;
    }
    
    cout << s << endl;
}  
int main(){
    suma(67638825,0);

    // int x,y,nr,nrmax=0, lenmax=0;
    // f >> x;
    // nr = 1;
    // while(f >> y){
    //     if(x==y)
    //         nr++;
    //     else{
    //         if(nr%2){//daca e impar
    //             if(lenmax<nr){
    //                 if(nrmax<x){
    //                     lenmax=nr;
    //                     nrmax=x;
    //                 }
    //             }
    //         }
    //         nr=1;
    //     }
    //     x=y;
    // }
    // cout << nrmax << ' ' << lenmax << endl;
    return 0;
}
