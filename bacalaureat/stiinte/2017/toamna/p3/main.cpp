#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int v[1000],max=0,min=1001;
    int x;
    while(f>>x){
        v[x]++;
        if(max<x)
            max=x;
        if(min>x)
            min=x;
    }
    int ratio=0,i=min;
    bool working=true;
    while(!ratio){
        if(v[i])
            ratio = i-min;
        i++;
    }
    for(int i=min;i<=max && working;i+=ratio)
        if(v[i]){
            for(int j=i+1;j<i+ratio;j++)
                if(v[j])
                    working=false;
        }else if(!v[i])
            working=false;
    if(working)
        cout << "DA";
    else cout << "NU";
    cout << endl;
    return 0;
}