#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
ofstream g("lista.out");
struct nod{ int info; nod *urm;};

void create(nod *&prim, nod *&ultim){
    int x;
    prim = ultim = NULL;
    nod *p;
    while(f >> x){
        p = new nod;
        p->info = x;
        p->urm = NULL;
        if(prim == NULL)
            prim=p;
        else
            ultim->urm = p;
        
        ultim=p;
    }
}

int suma (nod *p){
    int suma = 0;
    while(p->urm){
        if(p->info % 2 == 0){
            nod *next = p->urm;
            if(next->info %2 == 1){
                int val = next->info;
                next = next->urm;
                if(next->info %2 == 0)
                    suma+=val;
            }
        }
        p = p->urm;
    }
    return suma;
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    cout << suma(prim);
    return 0;
}