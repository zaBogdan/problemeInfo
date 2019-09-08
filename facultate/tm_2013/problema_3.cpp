#include <iostream>
#include <cmath>
using namespace std;

int highestValue(int n, int a[100][100]){
    int maxim = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (maxim < a[i][j])
            {
                maxim = a[i][j];
            }
        }
    }
    return maxim;
}
//Numarul de cifre ( punctul a )
int nr_cifre(int n){
    int nr = 0;
    while (n)
    {
        n /= 10;
        nr++;
    }
    return nr;
}

//Este prim? ( punctul b )
bool is_prim(int n){
    if (n == 0 || n == 1)
        return 0;
    if (n % 2 == 0)
        return 0;
    else
        for (int i = 3; i * i <= n; i++)
            if (n % i == 0)
                return 0;
    return 1;
}

int main()
{
    int n, a[100][100];
    cin >> n;

    //buildMatrix (punctul c)
    int nr_cif = nr_cifre(n);
    for (int i = 1; i <= nr_cif; i++)
    {
        a[i][1] = n % 10;
        for (int j = 2; j <= nr_cif; j++)
        {
            a[i][j] = a[i][j - 1] + i;
        }
        n /= 10;
    }

    //highestValue (punctul d)
    int nr_max = highestValue(nr_cif, a);

    //Submatrice cu determinant prim ( punctul e )
    bool ok=false;
    for(int i=1;i<nr_cif && !ok;i++){
        for(int j=1;j<nr_cif && !ok;j++){
            int det = abs(a[i][j]*a[i+1][j+1]-a[i+1][j]*a[i][j+1]);
            if(is_prim(det)){
                cout << "DA" << endl;
                ok=true;
            }
        }
    }
    if(!ok)
        cout << "NU" << endl;
    return 0;
}
