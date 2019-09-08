#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream g("cool.out");
const int NMax = 5000;
int c, n, k, v[NMax], f[1001], maxim, nr;

void cool()
{
    int maxy = 0, sequences = 0;
    int minim, maxim;
    for (int i = 1; i < n; i++)
    {
        minim = v[i], maxim = v[i];
        f[v[i]] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (f[v[j]]) break;
            f[v[j]] = 1;

            if (v[j] < minim) minim = v[j];
            if (v[j] > maxim) maxim = v[j];

            int lenght = j - i + 1;

            if (maxim - minim == lenght - 1){
                if (lenght>maxy){
                    maxy = lenght;
                    sequences = 1;
                }
                else if (maxy == lenght)
                    sequences++;
            }
        }
        memset(f, 0, sizeof(f));
    }
    g << maxy << endl << sequences;
    g.close();
}
void read();

int main()
{
    read();
    if (c == 1)
    {
        int min = 1001, max = 0;
        for (int i = 1; i <= k; i++)
        {
            f[v[i]]++;
            if (min > v[i])
                min = v[i];
            if (max < v[i])
                max = v[i];
        }
        int nr = 0;
        for (int i = min; i <= max; i++)
        {
            if (f[i] == 1)
                nr++;
            
        }
        if (nr == k)
                g << max << endl;
            else
                g << nr << endl;
        g.close();
    }
    else
        cool();

    return 0;
}
void read()
{
    ifstream f("cool.in");
    f >> c >> n >> k;
    for (int i = 1; i <= n; i++)
        f >> v[i];
    f.close();
}
