#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,len=1,maxlen=0;
    f >> x;
    while(f >> y){
        if(x!=y){
            len++;
            if(maxlen<len)
                maxlen=len;
        }else
            len=1;
        x=y;
    }
    cout << maxlen;
    cout << endl;
    return 0;
}