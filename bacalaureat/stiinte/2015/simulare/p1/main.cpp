#include <iostream>
using namespace std;

int main(){
    int n, v[10]={0};
    cin >> n;
    while(n){
        v[n%10]++;
        n/=10;
    }
    for(int i=0;i<=9;i++)
        if(v[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}