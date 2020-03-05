#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int v[100];

int main(){
    int k,s=0,x=0;
    cin >> k;
    while(s<k){
        x++;
        s=x*(x+1)/2;
    }
    cout << s-k+1 << endl;
    cout << endl; //development purpose.
    return 0;
} 