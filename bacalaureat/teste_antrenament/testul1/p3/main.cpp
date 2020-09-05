#include <iostream>
#include <fstream>
using namespace std;
ofstream g("bac.txt");

int main(){
    int n;
    cin >> n;
    while(n>0){
        g << n << ' ';
        n = (n+1)/3;
    }
    g << 1;
    return 0;
}