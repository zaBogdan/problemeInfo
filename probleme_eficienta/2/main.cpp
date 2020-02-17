#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
ofstream g("bac.txt");
int fr[205];

int main(){
    short n,m;
    int x; // voi stoca maximul
    //citire din fisiere pentru a putea testa mai usor. 
    f >> n;
    for(int i=0;i<n;i++){
        f >> x;
        fr[x]++;
    }
    int max = x;//ultimul element este maxim, intrucat sirul este ordonat crescator.
    f >> m; 
    for(int i=0;i<m;i++){
        f >> x;
        fr[x]++;
    }
    max = x>max ? x : max; //aleg maximul dintre cele doua siruri.
    x = -1;//il reinitializez cu -1 pentru a putea verifica paritatea ultimului element
    for(int i=0;i<=max;i++){
        if(fr[i] && x != i%2){
            x = i%2; // salvez paritatea ultimului element afisat
            g << i << ' '; // afisez.
        }
    }
    return 0;
}