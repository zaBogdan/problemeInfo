#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x, fr[101]={0},min=101,max=0;
    while(f >> x){
        if(x <= min)
            min=x;
        if(x >= max)
            max=x;
        fr[x]++;
        // min = min>x ? x : min;
        // max = max<x ? x : max;
    }
    bool ok=true;
    for(int i=min;i<=max;i++)
        if(fr[i])
            for(int j=i+1;j<=max;j++)
                if(fr[j]){
                    if(j-i>=2)
                        ok=true;
                    i=j-1;
                    j=max+1;
                }
    
    if(ok)
        cout << "Da";
    else cout << "Nu";
    cout << endl;
    return 0;
}