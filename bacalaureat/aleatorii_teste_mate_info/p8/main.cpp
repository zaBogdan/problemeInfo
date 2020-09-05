#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int x,y, lenmax=0, secv_lenmax=0,len=0;
    f >> x;
    if(x%10==0)
        len++;
    while(f>>y){
        if(y%10==0){
            len++;
        }else{
            if(len>lenmax){
                lenmax=len;
                secv_lenmax=1;
            }else if(len==lenmax){
                secv_lenmax++;
            }
            len=0;
        }
        x=y;
    }
    cout << lenmax << ' ' << secv_lenmax << endl;
    return 0;
}