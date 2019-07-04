#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 505,NMax2 = 505;
int p,n,m,a[NMax][NMax],viz[NMax][NMax],x,y,maxim,total;
int v[NMax2][2], parc;
int dx[] = {0,0,-1,0,1};
int dy[] = {0,1,0,-1,0};

void read();
void parcurgere(int x,int y){
    int lungime, directie;
    parc++; //numerotam parcurgerile in vectorul de vizitati
    while(a[x][y] && !viz[x][y]){
        directie = a[x][y]; //decidem directia
        viz[x][y]=parc; //setam din ce parcurgere face parte.
        lungime++; //crestem lungimea
        //trecem la urmatorul element pe x si y
        x+=dx[directie];
        y+=dy[directie];
    }

    //failsafeurile
    //1. Daca iesim din matrice
    if(!a[x][y]){
        v[parc][0] = lungime; // punem lungimea
        v[parc][1] = 0; // e o pozitie nefavorabila
    }else{
        //2. Daca ajungem de unde am inceput
        if(viz[x][y]==parc){ //daca am ajuns pe o pozitie vizitata, dar care face parte din traseu
            v[parc][0] = lungime; //lungimea este cea a traseului
            v[parc][1] = 1; // e o pozitie favorabila
        }else if(viz[x][y]){ //daca gasit un alt traseu
            v[parc][0] = lungime + v[viz[x][y]][0]; // este lungimea actuala + cea a traseului gasit. 
            v[parc][1] = v[viz[x][y]][1]; // pozitia este cea a traseului
        }
    }
    if(v[parc][1])
        total += v[parc][0] -  v[viz[x][y]][0];
}

int main(){
    read();
    ofstream g("arrows.out");
    if(p==1){
        parcurgere(x,y);
        if(v[parc][1])
            g << v[parc][0]*1000;
        else g << v[parc][0];
    }else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(!viz[i][j]){
                    parcurgere(i,j);
                    if(v[parc][1]){
                        if(maxim<v[parc][0])//gasesc maximum
                            maxim = v[parc][0];
                    }
                }
        if(p==2) g << total;
        else g << maxim*1000;
    }
    g.close();
        // cout << endl;
    return 0;
}

void read(){
    ifstream f("arrows.in");
    f >> p >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f >> a[i][j];
    f >> x >> y;
    f.close();
}