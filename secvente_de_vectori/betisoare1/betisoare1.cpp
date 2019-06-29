#include <iostream>
#include <fstream>
using namespace std;
ofstream g("betisoare1.out");
const int NMax = 1001;

void read(int &n, char s[NMax], int nr[])
{
    ifstream f("betisoare1.in");

    f >> n;
    f >> s;
    for (int i = 0; i < n; i++)
        nr[i] = s[i] - '0';
    f.close();
}
void det_sequence(int n, int nr[])
{
    int a = nr[0];
    int lung = 1, max1 = 0, max0 = 0, sec1 = 0, sec0 = 0;
    int lungmax1 = 0, lungmax2 = 0;

    for (int i = 1; i < n; i++)
    {
        if (a == nr[i])
            lung++;
        else
        {
            if (a == 1)
            {
                if (max1 < lung)
                {
                    max1 = lung;
                    sec1 = 1;
                }
                else if (max1 == lung)
                    sec1++;
            }
            else
            {
                if (max0 < lung)
                {
                    max0 = lung;
                    sec0 = 1;
                }
                else if (max0 == lung)
                    sec0++;
            }


            lung = 1;
            a = nr[i];
        }
    }

    //pentru ultimul element.
    if (a == 1)
    {
        if (max1 < lung)
        {
            max1 = lung;
            sec1 = 1;
        }
        else if (max1 == lung)
            sec1++;
    }
    else
    {
        if (max0 < lung)
        {
            max0 = lung;
            sec0 = 1;
        }
        else if (max0 == lung)
            sec0++;
    }
    if(max1 >= max0)
        g << 1 << ' ' << max1 << endl << sec1;
    else g << 0 << ' ' << max0 << endl << sec0;

}

int main()
{
    int n, nr[NMax];
    char s[NMax];
    read(n, s, nr);
    nr[n + 1] = -1;
    det_sequence(n, nr);
    return 0;
}