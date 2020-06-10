#include <iostream>
using namespace std;

int main(){
    int a,b,nr=0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        int d=2;
        while(d*d<=i){
            if(i%d==0 && d+1==i/d)
                nr++;
            d++;
        }
    }
    cout << nr;
    cout << endl;
    return 0;
}