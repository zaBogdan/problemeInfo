#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long k;
    cin >> k;
    for(int i=1;i<=sqrt(k);i++){
        if(k-i*i >= 0 && sqrt(k-i*i)==floor(sqrt(k-i*i)) && i<=sqrt(k-i*i))
              cout << i << ' ' << sqrt(k-i*i) << endl;
    }
    cout << endl; //development purpose.
    return 0;
}
