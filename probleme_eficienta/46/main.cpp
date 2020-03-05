#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int v[100];

int main(){
    int x,y,maxlen=0,len=1,offset=0,start=0;
    f >> x;
    while(f >> y){
        if(x%2!=y%2){
            v[offset++]=x;
            len++;
        }else{
            if(maxlen<len){
                v[offset++]=x;
                maxlen=len;
                len=0;
                start=offset-maxlen-1;
            }
        }
        x=y;
    }
    cout << maxlen << endl;
    for(int i=start;i<=start+maxlen;i++)
        cout << v[i] << ' ';
    cout << endl; //development purpose.
    return 0;
} 