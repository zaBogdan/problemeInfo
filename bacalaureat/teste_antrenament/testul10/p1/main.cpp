#include <iostream> 
using namespace std;

int main(){
    int n,p=1,p2=1,p4=1,p6=1,p8=1;
    cin >> n;  
    while(n){
        int c=n%10;
        if(c%2==0){
            if(c==2) p2=2;
            if(c==4) p4=4;
            if(c==6) p6=6;
            if(c==8) p8=8;
        }
        n/=10;
    }
    p = p2*p4*p6*p8;
    if(p==1)
        cout << -1;
    else cout << p;
    cout << endl;
    return 0;
}