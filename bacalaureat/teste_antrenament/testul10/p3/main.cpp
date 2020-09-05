#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int x,y,maxlen=0,len=0;
    f >> x;
    len=1;
    while(f >> y){
        if(y==x+1)
            len++;
        else{
            if(maxlen<len)
                maxlen=len;
            len=1;
        }
        x=y;
    }
    if(maxlen<len)
        maxlen=len;
    cout << maxlen;
    cout << endl;
    return 0;
}