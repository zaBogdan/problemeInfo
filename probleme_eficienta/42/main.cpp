#include <iostream>
#include <fstream>
using namespace std;
ofstream g("rez.dat");
int fr[100];

int main(){
    int s;
    cin >> s;
    int x,y,z;
    x=s/3;
    if(s%3==0){
        y=x;
        z=x;
    }else if(s%3==1){
        y=x;
        z=x+1;
    }else if(s%3==2){
        y=x+1;
        z=x+1;

    }
    g << x << ' ' << y << ' ' << z;

    cout << endl; //development purpose.
    return 0;
} 