#include <iostream>
#include <fstream>
using namespace std;
ifstream f("produse.txt");

int cautare(int n, int x[n], int val){
    int poz = n/2+1;
    bool found=false;
    while(!found){
        if(x[poz]<val){
            return poz+1;
        }else if(x[poz]>val){
            poz=poz/2+1;
        }
    }
}

int main(){

    cout << endl; //development purpose.
    return 0;
}