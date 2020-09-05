#include <iostream>
using namespace std;

//verificam daca sirul este palindrom.
bool is_palindrom(int n, int v[]){

    //verificam in oglinda, daca sirul este egal, pana la mijloc inclusiv. 
    for(int i=1;i<=n/2;i++)
        if(v[i]!=v[n-i+1])
            return 0;
    return 1;
}
void final(int nrPerm){
    //daca nu avem nicio permutare, inseamna ca sirul nu poate sa fie palindrom. 
    if(nrPerm==0)
        cout << "Nu";
    else cout << "Da";
}

//mutam fiecare element cu o pozitie spre stanga. 
int permutare(int n, int a[]){
    int k=0;
    //ne oprim cand gaseste palindromul, iar daca face mai multe permutari decat
    //cate elemente sunt inseamna ca nu exista solutie pentru acest sir.
    while(!is_palindrom(n,a) && k<n){
        //salvam primul element care trebuie sa ajunga pe ultima pozitie. 
        int first=a[1];
        //facem permutarile de la 1 la n-1
        for(int i=1;i<n;i++)
            a[i]=a[i+1];
        //punem primul element pe ultima pozitie. 
        a[n]=first;
        //crestem control.
        k++;
        for(int i=1;i<=n;i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    //daca k este n returnam 0, intrucat functia de afisare verifica acest lucru. 
    if(k==n)
        return 0;
    return k;
}

//citim numar de elemente (n) care va fii returnat modificat
void read(int &n, int a[]){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
}

int main(){
    int n,a[100];

    //citim vectorul si numarul de elemente
    read(n,a);
    //determinam numarul de permutari
    int lenght = permutare(n,a);

    //stabilim cauza.
    final(lenght);
    return 0;
}