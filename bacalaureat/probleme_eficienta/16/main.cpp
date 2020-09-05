#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sir.txt");

int main(){
    int n,x,y,len=1,lenmax=0,vmax=0;
    f >> n >> x;
    for(int i=1;i<n;i++){
        f >> y;
        if(x==y){
            len++;
        }else{
            if(lenmax<=len){
                lenmax=len;
                len=1;
                vmax = x;
            }else{
                len=1;
            }
            len=1;
        } 
        x=y;
    }
    if(lenmax<=len){
        lenmax=len;
        vmax=x;
    }//check for the last element.
    cout << vmax << ' ' << lenmax;
    cout << endl; //development purpose
    return 0;
}