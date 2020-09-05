#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int n,fr[10]={0};
    f >> n;
    int x,counter=0;
    while(f>>x){
        int power=0;
        while(x!=1){
            x/=10;
            power++;
        }
        fr[power]++;
    }
    int poz=0,power=0;
    for(int i=0;i<9;i++)
        if(fr[i] && poz < n){
            poz++;
            power=i;
        }
    if(poz==n){
        int number=1;
        for(int i=0;i<power;i++)
            number*=10;
        cout << number;
    }
    else
        cout << "Nu exista";
    cout << endl;
    return 0;
}