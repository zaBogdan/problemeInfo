#include <iostream> 
#include <fstream>
using namespace std;
struct nod{ int info; nod *prev, *next;};
ifstream f("lista.in");

void create(nod *&prim, nod *&ultim);
void afisare(nod *prim);
void afisare_back(nod *ultim);
void insert(nod *prim, int nr){
    nod *p = prim;
    nod *jhon = new nod;
    jhon->info = nr;
    // while(p!=q)
    jhon->next = p->next;
    jhon->prev = p;
    p->next = jhon;
    jhon->next->prev = jhon;
}

void stergere(nod *q){
    nod *p = q->prev;
    nod *n = q->next;
    p->next = n;
    n->prev = p;
    delete q;

}

int main(){
    nod *prim, *ultim;
    create(prim,ultim);
    // insert(prim, 1337); 
    stergere(prim->next);
    cout << "Afisare normala ";
    afisare(prim);
    cout << endl << "Afisare inversa ";
    afisare_back(ultim);
    cout << endl;
    return 0;
}

void create(nod *&prim, nod *&ultim){
    nod *p;
    int x;
    prim=ultim=NULL;
    while(f >> x){
        p = new nod;
        p->info = x;
        if(prim==NULL)
            prim = p;
        else{
            ultim->next = p;
            p->prev = ultim;
        }
        ultim = p;
    }
}
void afisare(nod *prim){
    nod *p = prim;
    while(p){
        cout << p->info << ' ';
        p = p->next;
    }
}
void afisare_back(nod *ultim){
    nod *p = ultim;
    while(p){
        cout << p->info << ' ';
        p = p->prev;
    }
}