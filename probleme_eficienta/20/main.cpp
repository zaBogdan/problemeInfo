#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,max1=99,max2=99;
    while(f >> x){
        if(x>99 && x<1000){
            if(x>max1){
                max2=max1;
                max1=x;
            }else if(x>max2 && x<max1){
                max2=x;
            }
        }
    }
    // cout << max1 << ' ' << max2 << endl;
    if(max1==99)
        cout << 0;
    else{
        short afisat=0;
        for(int i=999;i>=100&afisat<2;i--)
            if(i!=max1 && i!=max2){
                cout << i << ' ';
                afisat++;
            }
    }
    // cout << max1 << ' ' << max2;
    cout << endl; //development purpose
    return 0;
}