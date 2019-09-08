#include <iostream>
#include <cstring>
using namespace std;
int aF[256][8],d[256];
bool a[256][8];
char s[255];
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

//transform asciul in binar si il pun direct in matrice.
void convert_char(char c,int line){
    int asc = (int) c,poz=8;
    while(asc){
        a[line][poz] = asc%2;
        poz--;
        asc/=2;
    }
}
//construiesc matricea parcurgand sirul si apeland functia convert_char.
void convert_string(char s[255]){
    for(int i=0;i<strlen(s);i++)
        convert_char(s[i],i);
}
bool is_ok(int i,int j,int lenght,int n,int m,bool a[][8]){
    // merg mereu pozitiv, daca am gasit un patrat cu coltul de inceput in stanga sus, 
    // nu are sens sa mai caut si in celelate coluti ( stranga jos, dreapta sus/jos )
    // intrucat rezultatul va fii acelasi indiferent de perspectiva.
    bool element = a[i][j];
    int fi = i+lenght, fj = j+lenght;
    // verific daca inca mai sunt in matrice. Verificarea  ca ies doar in jos/dreapta
    // este necesara, dara in stanga si sus nu intrucat nu voi ajunge niciodata prin parcurgere.
    if(fi>n || fj > m)
        return 0;

    // parcurg patratul si daca gasesc o valoare care nu este corecta voi iesi din functie
    for(int x = i;x<=fi;x++)
        for(int y=j;y<=fj;y++)
            if(a[x][y]!=element)
                return 0;
    // daca toata matricea corespunde inseamna ca e corecta.
    return 1;
}

int submatrix_size(bool m[][8],int le,int col){
    int maxim = 0;
    for(int i=0;i<=le;i++)
        for(int j=1;j<=8;j++){
            int lenght = 1;
            while(is_ok(i,j,lenght,le,col,m)){
                lenght++;
            }
            if(maxim < lenght)
                maxim = lenght;
        }
    return maxim;
}

int main(){
    int zona = 0;
    cin >> s;
    int lenght = strlen(s)-1;
    convert_string(s); //construiesc matricea
    for(int i=0;i<=lenght;i++){
        for(int j=1;j<=8;j++)
            cout << a[i][j] <<' ';
        cout << endl;
    }
    cout << submatrix_size(a,lenght,8);
    return 0;
}