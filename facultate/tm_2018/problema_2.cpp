#include <iostream>
using namespace std;

void cifre(int n){
    int n1=0,n2=0;
    int pp=1,pi=1;
    while(n){
        if(n%2==1){
            n1=n1+(n%10)*pp;
            pp*=10;
        }else{
            n2=n2+(n%10)*pi;
            pi*=10;
        }
        n/=10;
    }
    cout << n1 << ' ' << n2 << endl;

}


int main(){
    int n;
    cin >> n;
    cifre(n);
    return 0;
}