#include <iostream>
using namespace std;

int main(){
    int n,p=1,m=0,k=0,c,x;
    cin >> n;
    while(n){
        cin >> x;
        for(int i=1;i<=k;i++)
            x=x/10;
        if(x) c=x%10;
        else c=n%10;
        m=c*p+m;
        n/=10;
        p*=10;
        k++;
    }
    cout << m;
            
    cout << endl;   
    return 0;
}