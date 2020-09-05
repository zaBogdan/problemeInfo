#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int fr[10];

int main(){
    int nr;
    while(f >> nr){
        while(nr){
            int uc = nr%10;
            fr[uc]++;
            nr=nr/10;
        }
    }
    for(int i=9;i>=0;i--)
        if(fr[i])
            for(int j=1;j<=fr[i];j++)
            cout << i;

    cout << endl; //development purpose.
    return 0;
}