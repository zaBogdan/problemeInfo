#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

void program(){
    int x,y,nr=0,count=0;
    f >> x;
    if(x%2==0)
        count=1;
    while(f>>y){
        if(y%2==0)
            count++;
        else{
            if(count>=2)
                nr++;
            count=0;
        }
        x=y;
    }
    if(count>=2)
        nr++;
    cout << nr;
}

int main(){
    int x,y,nr=0,count=0;
    f >> x;
    while(f>> x){
        if(x%2==0)
            count++;
        else{
            if(count>=2)
                nr++;
            count=0;
        }
    }
    if(count >=2)
        nr++;
    cout << nr;
    cout << endl;
    return 0;
}