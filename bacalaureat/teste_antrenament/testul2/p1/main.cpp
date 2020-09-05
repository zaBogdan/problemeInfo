#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d=1;
    while(d*d<n){
        if(n%d==0)
            cout << "(" << n/d << ' ' << d << ") ";
        d++;
    }
    cout << endl;   
    return 0;
}
