#include <iostream>
using namespace std;
const int NMax = 105;
int a[NMax][NMax], n;
struct coord{int x, y;} poz;

void calculare_suma();
void afisare();
bool worth_going();
void bordare();
void bkt(int x, int y, int pas);


coord next_step(int x, int y){
    bool ocupata = true;
    //daca totul este ok merge una sus si in dreapta.
    if (a[x - 1][y + 1] == 0)
    {
        poz.x = x - 1;
        poz.y = y + 1;
        ocupata = false;
        return poz;
    }
    //cazul 1. Cand este pe ultima coloana
    if (y == n && a[x - 1][1] == 0)
    {
        poz.x = x - 1;
        poz.y = 1;
        ocupata = false;
        return poz;
    }

    //cazul 2. Prima linie.
    if (x == 1 && a[n][y + 1] == 0)
    {
        poz.x = n;
        poz.y = y + 1;
        ocupata = false;
        return poz;
    }

    //cazul 3. Colt dreapta-sus
    if (x == n && y == n)
        if (a[n][1] == 0)
        {
            poz.x = n;
            poz.y = 1;
            ocupata = false;
            return poz;
        }

    //daca celula este ocupata face pas la stanga.
    if (ocupata)
    {
        poz.x = x;
        poz.y = y - 1;
        return poz;
    }
}


int main(){
    cin >> n;
    bordare();
    poz.x = n / 2 + 1;
    poz.y = n;
    bkt(poz.x, poz.y, 1);
}

void bordare(){
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = a[i][n + 1] = -1;
        a[0][i] = a[n + 1][i] = -1;
    }
}

bool worth_going(){
    //to generate all: pas == n * n+1
    for (int i = 1; i <= n; i++)
        if (!a[i][i])
            return 0;
    return 1;
}

void afisare(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
void calculare_suma(){
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += a[i][i];
    cout << s << endl;
}

void bkt(int x, int y, int pas){
    if (worth_going())
        calculare_suma();
    else
    {
        a[x][y] = pas;
        poz = next_step(x, y);
        bkt(poz.x, poz.y, pas + 1);
    }
}