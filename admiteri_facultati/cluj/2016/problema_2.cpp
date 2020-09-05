#include <iostream>
using namespace std;

int virusi(int n,int k){
    if(n<k) return 0;
    if(n%2==0) return virusi(n/2,k)+1;
    else return virusi(n+1,k)+1;
}


int main(){
    cout << virusi(11,3);
    return 0;
}