#include <iostream> 
using namespace std;

int main(){
    int n,s=0,n1=0,n3=0,n5=0,n7=0,n9=0;
    cin >> n;
    while(n){
        int c=n%10;
        if(c%2==1){
            if(c==1) n1=1;
            if(c==3) n3=3;
            if(c==5) n5=5;
            if(c==7) n7=7;
            if(c==9) n9=9;
        }
        n/=10;
    }
    s=n1+n3+n5+n7+n9;
    cout << s;
    cout << endl;
    return 0;
}