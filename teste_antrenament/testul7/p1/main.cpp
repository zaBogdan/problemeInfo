#include <iostream> 
using namespace std;

int main(){
    int n,p,nr=0;
    cin >> n >> p;
    while(n%p==0){
        n/=p;
        nr++;
    }
    cout << nr;
    cout << endl;
    return 0;
}