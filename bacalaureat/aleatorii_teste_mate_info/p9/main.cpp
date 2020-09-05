#include <iostream>
using namespace std;

int nrmax(int a,int b){
    if(a>b)
        swap(a,b);
    int fr[10]={0};
    while(a){
        int cif = a%10;
        if(cif%2)
            fr[cif]=1;
        a/=10;
    }
    while(b){
        int cif=b%10;
        if(cif%2 && fr[cif]==1)
            fr[cif]=2;
        b/=10;
    }
    int c =0;
    for(int i=9;i>=0;i--)
        if(fr[i]==2)
            c = c*10+i;
    return c;
            
}

int main(){
    cout << nrmax(45013,215578);
    return 0;
}