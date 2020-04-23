#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("bac.in");
int fr[100];

int main(){
    int x,y, smax=0, dmax=0,nr1,nr2;
    f >> x;
    while(f >> y){
        if(x > 0 && y > 0){
            int lsum = x+y;
            int ldif = abs(x-y);
            if(lsum > smax){
                dmax = ldif;
                smax = lsum;
                nr1 = x,nr2=y;
            }else if(lsum == smax){
                if(ldif>dmax){
                    dmax = ldif;
                    smax = lsum;
                    nr1 = x,nr2=y;
                }
            }
        }
        x=y;
    }
    if(nr1 < nr2){
        int aux=nr1;
        nr1=nr2;
        nr2=aux;
    }
    cout << nr1 << ' ' << nr2;
    cout << endl; //development purpose.
    return 0;
} 