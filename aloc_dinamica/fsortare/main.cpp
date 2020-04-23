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
void sortareCrescator(nod *&prim){
    nod *p = prim;
    bool sortat;
    do{
        p = prim;
        sortat = true;
        while(p->urm){
            if(p->info > p->urm->info){
                int aux = p->info;
                p->info = p->urm->info;
                p->urm->info = aux;

                sortat=false;
            }
            p = p->urm;
        }
    }while(!sortat);
}



int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    sortareCrescator(prim);
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