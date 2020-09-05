#include <iostream>
#include <fstream>
using namespace std;
ifstream f("produse.txt");
int fr[1000];

int main(){
    //tipul, cantitatea pret.
    int x,y,z,max=0;
    while(f >> x >> y >> z){
        fr[x] += y*z;
        max = x>max ? x : max;
    }
    for(int i=1;i<=max;i++)
        if(fr[i])
            cout << i << ' ' << fr[i] << endl; 

    cout << endl; //development purpose.
    return 0;
}