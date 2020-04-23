#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
struct nod{ int info; nod *urm;};

//helper functions 
void create (nod *&prim, nod *&ultim);
void afisare(nod *prim);
nod* element(nod *p, int poz){
    nod *prim = p;
    int nr=0;
    while(prim){
        if(poz==nr)
            return prim;
        prim = prim->urm;
        nr++;
    }
    return NULL;
}

//my function
void sterge(nod * & p, nod * q){
    nod *prim = p;
    if(p==q)
        p = q->urm;
    else
    while(prim){
        if(prim->urm==q){
            nod *next_nod = prim;
            next_nod->urm = q->urm;
        }
        
        prim = prim->urm; 
    }
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    sterge(prim); 
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