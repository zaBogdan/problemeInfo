#include <iostream>
#include <cmath>
using namespace std;

int transformareBaza10(int b,int n){
    int s=0,k=0;
    while(n){
        int c=n%10;
        int p = 1;
        for(int i=0;i<k;i++)
            p*=b;
        s+=c*p;
        // s+= c*pow(b,k);
        k++;
        n/=10;
    }
    return s;
}
int main(){
    cout << transformareBaza10(2,10010);
    cout << endl;
    return 0;
}