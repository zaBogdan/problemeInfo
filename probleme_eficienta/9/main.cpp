#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int v[1001];

//Se poate mai eficient decat O(n)?
int main(){
    int i=0;
    f >> v[i];
    int st = i, dr=i,lmax=0, sq,dq;
    while(f >> v[++i]){
        if(v[i-1]>v[i]){ //incep sa construiesc sirul.
            // cout << v[i-1] << ' ' << v[i] << endl;
            dr=i;
        }else{
            //verific daca trebuie sa mut pointerul din stanga, adica daca am gasit un sir 
            //cu lungime mai mare decat precedentul
            if(lmax < dr-st){
                lmax = dr-st;//actualizez lungimea maxima. 
                sq = st, dq = dr;//salvez secventa.
            }//altfel mut pointerul de stanga pe pozitia urmatoare.
            st = i;
            dr = i;
        }
    }
    for(int j=sq;j<=dq;j++)
        cout << v[j] << ' ';
    cout << endl;
    return 0;
}