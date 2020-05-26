#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int x,y,firstneg=0, lastneg=0,i=0;
    f >> x;
    if(x<0)
        firstneg=i;
    while(f >> y){
        i++;
        if(y<0){
            if(!firstneg)
                firstneg=i;
            lastneg=i;
        }
        x=y;
    }
    cout << lastneg-firstneg+1;
    cout << endl;   
    return 0;
}