#include <iostream>
#include <fstream> 
#include <cmath>
using namespace std;
ofstream g("bac.txt");

int main(){
    int n,x;
    cin >> n >> x;
    for(int i=n;i>=1;i--){
        int last;
        if(i%2==0){
            last = (i/2)*x + (i/2-1)*(x-1);
        }else{
            last = (i/2)*x + (i/2)*(x-1);
        }
        g << last << ' ';
    }
    cout << endl;
    g.close();
    return 0;
}