#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int fr[101];

int main(){
    int minlength=30001, maxvalue=0, x;
    int lvalue=0, llength=0;
    while(f >> x){
        if(x!=0){
            llength++;
            lvalue = x>lvalue ? x : lvalue;
        }else{
           if(llength<minlength){
               minlength = llength;
               maxvalue = lvalue;
           }
            lvalue=0;
            llength=0;
        }
    }
    cout << maxvalue;
    cout << endl; //development purpose.
    return 0;
}