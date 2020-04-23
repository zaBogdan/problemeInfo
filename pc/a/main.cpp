#include <iostream>
#include <cmath>
using namespace std;
struct coord{int par,impar;} nr; 

void check(char a){
    int nr2 = a-'0';
    if(nr2%2==0) nr.par++;
    else nr.impar++; 
}
int main(){
    int left=0;
    int n;
    cin >> n;
    char* str = new char[n];
    cin >> str;
    for(int i=0;i<n/2;i++){
        check(str[i]);
        check(str[n-i-1]);
    }
    if(n%2==1){
        check(str[n/2]);
    }
    if(nr.par!=nr.impar)
        left = abs(nr.par-nr.impar);
    cout <<left << endl;
}