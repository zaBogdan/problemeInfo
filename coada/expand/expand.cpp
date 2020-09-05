#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct cuv{int poz; char cuv[20][20];} v[30];
struct coord{int k;char cuv[20];} c[15000001];
int k;
char litera, cuv[20];

void read();
int coada(){
    int prim,ultim;
    char building[20]="";
    prim = ultim = 1;
    c[prim].cuv[0] = litera; //prima litera
    c[prim].cuv[1] = '\0';
    c[prim].k = 0; //mutarea initiala: numarul 0;
    while(prim<=ultim){
        strcpy(building, c[prim].cuv); //lucrez cu fiecare cuvant
        for(int i=0;i<strlen(building);i++){
            char lit = building[i]; //pentru fiecare litera
            if(strlen(building)<=strlen(cuv)+1){ //daca lungimea este mai mica continui
                for(int j=1;j<=v[lit-'a'+1].poz;j++){ //parcurg fiecare cartonas al literei respective
                    char insider[20];
                    strcpy(insider,v[lit-'a'+1].cuv[j]);
                    if(strlen(building)+strlen(insider)<=strlen(cuv)+1){//daca nu depaseste lungimea
                        char aux[20];
                        strcpy(aux, building);
                        strcpy(aux+i,insider);
                        strcat(aux,building+i+1);//copiez cuvantul
                        if(strlen(aux)<=strlen(cuv)){
                            ultim++;
                            c[ultim].k = c[prim].k+1;
                            strcpy(c[ultim].cuv,aux);
                        }
                        if(strcmp(cuv, aux)==0) return c[ultim].k;
                    }
                }
            }
        }
        prim++;
    }
    return 0;
}

int main(){
    read();
    ofstream g("expand.out");
    g << coada();
    g.close();
    return 0;
}

void read(){
    ifstream f("expand.in");
    f >> litera >> cuv >> k;
    for(int i=1;i<=k;i++){
        char x,cuv2[20];
        f >> x;
        int poz = x-'a'+1;
        v[poz].poz++;
        f >> v[poz].cuv[v[poz].poz];
    }
    f.close();
}
