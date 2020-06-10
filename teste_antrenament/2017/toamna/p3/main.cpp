#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int v[1000],max=0,min=1001;
    int x;
    while(f>>x){
        v[x]++;
        max = x>max ? x : max;
        min = x<min ? x : min;
    }
    int ratio=0,i=min;
    bool working=true;
    while(!ratio){
        if(v[i])
            ratio = i-min;
        i++;
    }
    for(int i=min;i<=max;i+=ratio)
        if(!v[i])
            working=false;
    if(working)
        cout << "DA";
    else cout << "NU";
    cout << endl;
    return 0;
}