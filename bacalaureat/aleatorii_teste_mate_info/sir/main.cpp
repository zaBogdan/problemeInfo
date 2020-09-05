#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

void patrate(int x, int y){
    char s[] = "";
    int sum=0;
    bool displayed = false;
    for(int i=x;i<=y;i++){
        if(sqrt(i)==floor(sqrt(i))){
            if(displayed)
                cout << "+";
            cout << i;
            sum += i;
            displayed = true;
        }
    }
    cout << "=" << sum;
    cout << endl;
}

int main(){
    // patrate(10,50);
    int k,x,y,mlen=0,len=0,siruri=0;
    f >> k >> x;
    while(f >> y){
        if(x%k==0 && y%k==0){
            len++;
        }else{
            if(mlen==len)
                siruri++;
            if(mlen<len)
                mlen = len;
            len=!x%k ? 0 : 1;
        }
        x=y;
    }
    if(mlen==len)
        siruri++;
    cout << mlen << ' ' << siruri << endl;
    return 0;
}