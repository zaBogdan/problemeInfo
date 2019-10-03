#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
ofstream g("lista.out");
struct nod{ int info; nod *urm;};


void afisare(nod *prim){
    nod *p = prim;
    while(p){
        cout << p->info << ' ';
        p = p->urm;
    }
    cout << endl;

}

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

void sterge(nod *&p){
    nod *next;
    nod *q;
    while(!p->info%2 && p){
        next = p;
        p = p->urm;
        delete next;
    }
    q=p;
    if(q)
        while(q->urm && p){
            next = q->urm;
            if(next->info%2==0){
                q->urm = next->urm;
                delete next;
            }
            q = q->urm;
        }
}

int main(){
    nod *prim,*ultim;
    create(prim,ultim);
    sterge(prim);
    afisare(prim);
    return 0;
}