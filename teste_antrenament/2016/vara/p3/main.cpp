#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("numere.in");

int main(){
    int x,y,afisat=0;    
    f >> x;
    while(f >> y){
        for(int i=x+1;i<y;i++){
            cout << i << ' ';
            afisat=1;
        }
        x=y;
    }
    if(!afisat)
        cout << "Nu exista";
    cout << endl;
    return 0;
}