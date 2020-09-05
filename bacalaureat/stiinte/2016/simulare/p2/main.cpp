#include <iostream>
using namespace std;

int sPar(int n){
    bool found = false;
    int paritate = n%2;
    if(paritate)
        n++;
    else n+=2;
    while(!found){
        int d=2,s=0;
        while(d<=n/2){
            if(n%d==0)
                s+=d;
            d++;
        }
        cout << n << ' ' << s << endl;
        if(s%2==0)
            found=true;
        n+=2;
    }
    return n-2;
}

int main(){
    int n;
    cin >> n;
    cout << sPar(n);
    cout << endl;
    return 0;
}