#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int fr[101];

int main(){
    int n, x, max=0, min=501;
    while(f >> x){
        if(x>9 && x<100){
            fr[x]++;
            max = x>max ? x : max;
            min = x<min ? x : min;
        }
    }
    g << max << ' ' << fr[max] << endl;
    g << min << ' ' << fr[min];
    cout << endl; //development purpose.
    return 0;
}