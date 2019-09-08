#include <iostream>
using namespace std;

//punctul a) 4.

double suma(int n){
    double s=0;
    for(int i=1;i<=n;i++){
        int semn = i%2==0? -1 : 1;
        double termen = (double) semn/(2*i);
        s+=termen; 
    }
    return s;
}

int main(){
    cout << suma(4);
    return 0;
}