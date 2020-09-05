#include <iostream>
#include <fstream> 
using namespace std;
ofstream g("bac.txt");

int main(){
    int n;
    cin >> n;
    while(n!=3){
        g << n << ' ';
        n=(n-2)/2;
    }
    g << n << ' ' << 0;

    cout << endl;
    return 0;
}