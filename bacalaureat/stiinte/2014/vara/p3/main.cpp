#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int fr[10]={0},x;
    while(f>>x){
        while(x){
            fr[x%10]++;
            x/=10;
        }
    }
    int max1=0,max2=0,pos1,pos2;
    for(int i=0;i<=9;i++){
        if(max1<fr[i]){
            max2=max1;
            pos2=pos1;
            max1=fr[i];
            pos1=i;
        }else if(max2<=fr[i]){
            max2=fr[i];
            pos2=i;
        }
    }
    cout << pos1 << ' ' << pos2;
    cout << endl;
    return 0;
}