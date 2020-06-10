#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,y,max=0;
    f >> x;
    max=x;
    cout << max << ' '
    while(f >> y){
        if(max<=y){
            max=y;
            cout << max << ' ';
        }
        x=y;
    }
    cout << endl;
    return 0;
}