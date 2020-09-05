#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lista.in");
struct node{ char key; node *next;};

//helper functions 
void create (node *&prim, node *&ultim);
void afisare(node *prim);
node* element(node *p, int poz);

//my function
bool palindrom(node *l){
    node *prim = l;
    string c;
    int nr =0;
    while(prim){
        c += prim->key;
        prim = prim->next;
    }
    int len = c.length()-1;
    for(int i=0;i<len/2+1;i++)
        if(c[i]!=c[len-i])
            return 0;
    return 1;
}

int main(){
    node *prim,*ultim;
    create(prim,ultim);
    cout << palindrom(prim);
    cout << endl;
    return 0;
}

void create(node *&prim, node *&ultim){
    char x;
    prim=ultim=NULL;
    node *p;
    while(f >> x){
        p = new node;
        p->key = x;
        p->next = NULL;
        if(prim==NULL)
            prim = p;
        else ultim->next = p;
        ultim = p;
    }
}

void afisare(node *prim){
    node *p = prim;
    while(p){
        cout << p->key << ' ';
        p = p->next;
    }
}
node* element(node *p, int poz){
    node *prim = p;
    int nr=0;
    while(prim){
        if(poz==nr)
            return prim;
        prim = prim->next;
        nr++;
    }
    return NULL;
}