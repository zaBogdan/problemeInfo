#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");

int main(){
    int n, v[1000],c1,c2;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f >> c1 >> c2;
    f.close();
    int mij=n/2, high,low;
    

    return 0;
}