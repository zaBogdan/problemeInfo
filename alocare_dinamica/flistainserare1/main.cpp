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
void inserare(nod *&p, nod * q, int x){
    nod *jhon = new nod;
    jhon->info = x;
    if(p==q){
        jhon->urm = q->urm;
        p = jhon;
    }else{
        nod *prim = p;
        while(prim){
            if(prim->urm == q){
                jhon->urm = q;
                prim->urm = jhon;
                break;
            }
            prim = prim->urm;
        }
    }
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    nod *q = element(prim, 0);
    inserare(prim, prim, 1200);
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