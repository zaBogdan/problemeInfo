#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int x, max1=0,max2=0;
    while(f >> x){
        if(x%10==0 && x/10%10==2){
            if(max1<x) max2=max1,max1=x;
            else if(max2<x) max2=x;
        }
    }
    cout << max2 << ' ' << max1;
    cout << endl;   
    return 0;
}