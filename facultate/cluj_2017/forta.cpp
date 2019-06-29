#include <iostream>
using namespace std;
struct grupuri
{
    int pozitie, elemente[100];
} grup[100];

int count_binary(int x){
    int nr = 0;
    while (x)
    {
        if (x % 2 == 1)
            nr++;
        x /= 2;
    }
    return nr;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int number = 0;
    for (int i = 1; i <= n; i++)
    {
        int forta = count_binary(v[i]);
        if (grup[forta].pozitie == 0)
            number++;
        int x = grup[forta].pozitie + 1;
        grup[forta].elemente[x] = v[i];
        grup[forta].pozitie++;
    }

    cout << number << endl;
    for(int i=1;i<=number;i++){
        for(int j=1;j<=grup[i].pozitie;j++)
            cout << grup[i].elemente[j] << ' ';
        cout << endl;
    }
    return 0;
}