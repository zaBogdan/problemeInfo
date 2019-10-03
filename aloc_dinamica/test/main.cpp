#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
ofstream g("lista.out");
struct lista{ int info; lista *next;};

void create(lista *&prim, lista *&ultim){
    int x;
    prim = ultim = NULL;
    lista *p;
    while(f >> x){
        p = new lista;
        p->info = x;
        p->next = NULL;
        if(prim == NULL)
            prim=p;
        else
            ultim->next = p;
        
        ultim=p;
    }
}
void afisare(lista *prim){
    lista *p = prim;
    while(p){
        g << p->info << ' ';
        p = p->next;
    }

}

int main(){
    lista *prim, *ultim;

    create(prim,ultim);
    afisare(prim);
    return 0;
}
