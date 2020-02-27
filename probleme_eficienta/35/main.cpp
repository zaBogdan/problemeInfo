#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int x,sp,sip,ap=0,min=1000000000;
    while(f>>x) {
        int cx =x;
        sp=sip=0;
        while(x){
            int uc = x%10;
            if(uc%2==0)
                sp+=uc;
            else sip+=uc;
            x/=10;
        }
        if(sip==sp){
            if(cx < min){
                ap=1;
                min=cx;
            }else if (cx==min)
                ap++;
        }
    }
    cout << min << ' ' << ap;
    cout << endl; //development purpose.
    return 0;
}