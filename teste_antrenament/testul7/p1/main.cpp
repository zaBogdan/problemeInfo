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
/*
int a,b;
a=2,b=3;
cout << (a+b)/2.0;
cout << endl;
//sau
cout << (a+b)*1.0/2;
cout << endl;
//sau
cout << (float)(a+b)/2;
cout << endl;
cout << (a+b)/2;
cout << endl;
*/