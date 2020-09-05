#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int x,fr[10]={0};
    int n;
    f >> n;
    while(f >> x){
        int p = 0;
        while(x){
            x/=2;
            p++;
        }
        fr[p]=1;
    }
    int poz=1,p=0;
    for(int i=0;i<=9;i++)
        if(fr[i] && poz<n){
            p = i;
            poz++;
        }
    int nr = 1;
    for(int i=0;i<p;i++)
        nr*=2;
    cout << nr;
    f.close();
    cout << endl;
    return 0;
}