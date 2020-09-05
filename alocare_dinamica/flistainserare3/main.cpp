#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
struct nod{ int info; nod *urm;};

//helper functions 
void create (nod *&prim, nod *&ultim);
void afisare(nod *prim);
nod* element(nod *p, int poz);

//my function
void inserare(nod *&p){
    nod *jhon;
    nod *prim = p;
    while(prim){
        nod *next_nod = prim->urm;
        if(next_nod && next_nod->info % 2 == 0){
            jhon = new nod;
            jhon->info = next_nod->info*2;
            jhon->urm = next_nod;
            prim->urm = jhon;
            prim = next_nod;
        }else prim = prim->urm;
    }

    //primul element
    if(p->info % 2 == 0){
        jhon = new nod;
        jhon->info = p->info*2;
        jhon->urm = p;
        p = jhon;
    }
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    inserare(prim);
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