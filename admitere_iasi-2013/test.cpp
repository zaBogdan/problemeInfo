#include <iostream>
#include <cmath>
using namespace std;
int func1(int m,int n){
    if(m>0){
        if(n==0) return func1(m-1,1);
        if(n>0) return func1(m-1,func1(m,n-1));
    }
    return n+1;
}
int main(){

    cout << func1(2,1) << endl;
    return 0;
}