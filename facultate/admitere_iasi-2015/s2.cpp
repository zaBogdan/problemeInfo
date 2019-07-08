#include <iostream>
using namespace std;

int f1(int x);
int f2(int x);

int f2(int x){
    if(x<10) {return 3*x;}
    else {return 2*f1(x/2);}
}
int f1(int x){
    if(x<7){ return 3+x;}
    else { return 2+f2(x-2);}
}

int main(){
    int n;
    cin >> n;
    cout << f1(n);
    return 0;
}