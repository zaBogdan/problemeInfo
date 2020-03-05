#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("bac.dat");
int low[1000],high[1000],first=0;

int length(int a, int b){
    if(a==0 && !high[a])
        return high[b];
    if(b==0 && !high[b])
        return abs(low[-first]-low[-a]+1);
    int ok = (a*b)>0;
    a = a<0 ? low[-a] : high[a];
    b = b<0 ? low[-b] : high[b];
    return ok==1 ? abs(b-a+1) : abs(low[-first]-a+1)+b;
}

int main(){
    int n,m,last=0,ap=0,ap2=0;
    f >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        f >> x;
        if(x<0){
            if(!first)
                first = x;
            for(int i=x-1;i>first;i--)
                low[-i]=ap2;
            ap2++;
            low[-x]=ap2;
            first=x;
        }else if(x>=0){
            for(int i=last;i<x;i++){
                high[i]=ap;
            }
            ap++;
            last=x+1;
            high[x]=ap;
        }
    }
    int max=0;
    int x,y,val1,val2;
    f >> x;
    for(int i=2;i<=m;i++){
        f >> y;
        int len = length(x,y);
        if(max <= len){
            max=len;
            val1=x;
            val2=y;
        }
        x=y;
    }
    cout << val1 << ' ' << val2;
    cout << endl; //development purpose.
    return 0;
} 