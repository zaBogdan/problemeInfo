#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
struct nod{ int info; nod *urm;};

//helper functions 
void create (nod *&prim, nod *&ultim);
void afisare(nod *prim);

//my function
void adaugare(nod *&p, int x){
    nod *prim = p;
    if(prim==NULL){
        p = new nod;
        p->info = x;
        p->urm = NULL;
    }else{
        while(prim->urm){
            prim = prim->urm;
        }
        nod *new_nod;
        new_nod = new nod;
        new_nod->info = x;
        new_nod->urm = NULL;
        prim->urm = new_nod;
    }

}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    adaugare(prim, 123087666); 
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