#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
struct nod{ int info; nod *urm;};

//helper functions 
void create (nod *&prim, nod *&ultim);
void afisare(nod *prim);

//my function
int numarare(nod *p){
    nod *prim = p;
    if(prim == NULL)
        return 0;
    int nr=0;
    while(prim->urm){
        nod *next = prim->urm;
        if(prim->info == next->info) nr++;        
        prim = prim->urm;
    }
    return nr;
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    cout << numarare(prim) << endl;
    afisare(prim);
    cout << endl;
    return 0;
}

void create(nod *&prim, nod *&ultim){
    int x;
    prim=ultim=NULL;
    nod *p;
    while(f >> x){
        p = new nod;
        p->info = x;
        p->urm = NULL;
        if(prim==NULL)
            prim = p;
        else ultim->urm = p;
        ultim = p;
    }
}

void afisare(nod *prim){
    nod *p = prim;
    while(p){
        cout << p->info << ' ';
        p = p->urm;
    }
}