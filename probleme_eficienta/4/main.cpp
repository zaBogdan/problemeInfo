#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");

int max_cif(int x[100], int n){
    int max = 0;
    for(int i=0;i<n;i++)
        if(x[i]>99 && x[i]<1000)
            max = x[i]>max? x[i] : max;
    return max; //daca nu exista numere de 3 cifre va afisa valoarea cu care a fost initializat, adica 0;
}
int main(){
    //se poate mult mai eficient daca nu folosim subprogramul max_cif...
    int n,v[101],lmax=0,gmax=0;
    f >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            f >> x;
            v[j]=x;
        }
        lmax = max_cif(v,n);
        gmax = lmax>gmax ? lmax : gmax;
    }
    cout << gmax << endl;
    return 0;
}