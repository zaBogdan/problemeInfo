#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
int fr[100];

int main(){
    float x,max=-1000000000;
    int start=0,finish=0,nr=0;
    while(f >> x){
        nr++;
        if(x > max){
            start=nr;
            max=x;
        }else if(x==max){
            finish = nr;
        }
    }
    cout << start << ' ' << finish;
    cout << endl; //development purpose.
    return 0;
} 