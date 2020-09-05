#include <iostream>
using namespace std;

int main(){
    int a,b,ok=0;
    cin >> a >> b;
    for(int i=b;i>=a;i--){
        int n=i,d=2,s=0;
        while(d<=n/2){
            if(n%d==0)
                s+=d;
            d++;    
        }
        if(i<s){
            ok=1;
            cout << i << ' ';
        }
    }
    if(!ok)
        cout << "nu exista";
    cout << endl;
    return 0;
}