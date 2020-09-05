#include <iostream>
using namespace std;

int function(int n,int k){
    if(!k || n==k) return 1;
    return function(n-1,k-1)+function(n-1,k);
}
int main(){
    cout << function(5,3) << endl;
}