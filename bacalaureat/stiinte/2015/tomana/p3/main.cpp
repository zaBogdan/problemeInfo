#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int n,s1=0,s2=0;
    f >> n;
    int x,i=1;
    while(f>>x){
        if(i<=n){
            if(x%2) s1+=x;
        }
        else{
            if(!(x%2)) s2+=x;
        }
        i++;
    }
    cout << s1*s2;
    cout << endl;
    return 0;
}