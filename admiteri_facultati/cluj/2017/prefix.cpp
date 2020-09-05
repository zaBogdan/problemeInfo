#include <iostream>
using namespace std;
int f[10];

void citire_date(int &nr,int &n, int &m);
int cifra_control(int x);
void afisare(int lungime, int prefix[]);


//construim un vector cu elementele numarului, fiind puse de la coada la cap.
//incepem de la ultimul element al vectorului si mergem pana cand nu gaseste o cifra
//in vectorul de frecventa. 
int prefixMaxim(int nr,int cifre[]){
    //face o copie a vectorului de frecventa pe care o descompune in vector.
    int cnr = nr;
    int lungime=1;
    while(cnr){
        cifre[lungime++]=cnr%10;
        cnr/=10;
    }
    bool ok=true;
    lungime--;
    //pun lungimea initiala pe pozitia 0 din vector. 
    cifre[0]=lungime;

    //mergem de la ultimul element pana cand in vectorul de frecventa
    //nu exista cifra de pe pozitia aceea. lungimea este 
    for(int i=cifre[0];i>=1 && ok;i--){
        if(!f[cifre[i]]){
            ok=false;
            lungime-=i;
        }
    }
    return lungime;
}


int main()
{
    int nr,n,m,cifre[10];

    citire_date(nr,n,m);
    int lenght = prefixMaxim(nr,cifre);
    afisare(lenght, cifre);
    return 0;
}


//citeste datele nr,n,m si apoi fiecare element din matrice
//si ii face direct cifra de control, salvand timp si memorie.
//cifrele care apar macar odata sunt puse intr-un vector de frecventa. 
void citire_date(int &nr,int &n, int &m){
    cin >> nr;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        int x;
        cin >> x;
        int cif = cifra_control(x);
        f[cif]++;
    }
}


//determina suma cifrelor numarului n recursiv
int cifra_control(int x){
    if(x<9) return x;
    //make the sum for n;
        int s=0;
        while(x>0){
            s+=x%10;
            x/=10;
        }
    cifra_control(s);
}

//afiseaza prefixul.
void afisare(int lungime, int prefix[]){
    for(int i=prefix[0];i>prefix[0]-lungime;i--)
        cout << prefix[i];
    cout << endl;
}
