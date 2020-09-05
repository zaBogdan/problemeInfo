#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const short NMax = 55; 
char c[NMax][NMax],a[NMax][NMax];
int n,m,k;

//citeste/afiseaza
void read();
void afisare();

//introduce cuvantul in matrice pe line/coloana
void write_line(char word[NMax],int x,int y);
void write_colon(char word[NMax],int x,int y);

//imi cauta un cuvant pe linie si pe coloana
bool search_matrix(char word[NMax], int lenght);
//verifica daca am gasit toate cuvintele in matrice
bool filled();


void bkt(int x,int y){
    if(filled()) afisare();
    else
        for(int i=1;i<=k;i++){
            
        }
}

int main(){
    read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]='0';
    write_line(c[1], 1,1);
    write_line(c[2], 1,2);
    write_line(c[3], 2,2);
    write_colon(c[4],1,3);
    bkt(1,1);
    return 0;
}

void read(){
    ifstream f("cuvinte.in");
    f >> k >> n >> m;
    for(int i=1;i<=k;i++)
        f >> c[i]; 
    f.close();
}
void afisare(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(a[i][j]=='0')
                cout << "-";
            else cout << a[i][j];
        cout << endl;
    }
}
bool search_matrix(char word[NMax], int lenght){
    //functia cauta un cuvant pe linii si pe coloane. Daca il gaseste returneaza 1, altfel 0
    for(int i=1;i<=n;i++){
        //pentru fiecare linie caut cu un offset,pana la m-lungime. Initial este 0. 
        for(int j=1;j<=m-lenght+1;j++){
            char aux[NMax]="";
            strncpy(aux,a[i]+j,lenght);
            aux[lenght+1]='\0';
            //daca am gasit termin cautarea, return 1.
            if(strcmp(aux,word)==0)
                return 1;
        }
    }
    //daca nu am gasit nimic pe linie, vom cauta pe fiecare coloana.
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n-lenght+1;i++){
            char aux[NMax]="";
            int poz = 0;
            for(int k=i;k<=i+lenght;k++)
                aux[poz++] = a[k][j];
            aux[poz]='\0';
            //daca am gasit cuvantul pe coloana, return 1
            if(strcmp(aux,word)==0)
                return 1;
        }
    }
    //daca dupa ambele cautari nu am iesit din functie inseamna ca nu exista. 
    return 0;
}
bool filled(){
    int nr = 0;
    //caut cuvintele in matrice si vad daca le gasesc pe toate. 
    for(int i=1;i<=k;i++){
        if(search_matrix(c[i],strlen(c[i]))){
            cout << "GASIT: " << c[i] << endl;
            nr++;
        }
    }
    //daca am gasit toate cuvintele din matrice pot sa afisez cazul.
    if(nr==k)
        return 1;
    return 0;
}
void write_line(char word[NMax],int x,int y){
    int lenght = strlen(word);
    //plasez cuvantul pe linia x, incepand de la pozitia y
    strncpy(a[x]+y,word, lenght);
}
void write_colon(char word[NMax],int x,int y){
    int lenght = strlen(word);
    //plasez cuvantul pe coloana y, incepand de la linia x
    for(int i=x;i<=x+lenght-1;i++){
        a[i][y]=word[i-x];
    }
}