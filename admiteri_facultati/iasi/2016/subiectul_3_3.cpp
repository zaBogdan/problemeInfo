#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ifstream f("progresie2.in");
struct coord {int x, y, nr;};
const short NMax = 10;

int getLenght(int n, int m, int a[NMax][NMax], int i1, int j1, int i2, int j2){
    coord get_ratio, last;
    int lenght = 2;
    get_ratio.x = i2 - i1;
    get_ratio.y = j2 - j1;
    get_ratio.nr = a[i2][j2] - a[i1][j1];
    cout << a[i1][j1] << endl;
    cout << a[i2][j2] << endl;
    last.x = i2;
    last.y = j2;
    last.nr = a[last.x][last.y];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j - last.y == get_ratio.y && i - last.x == get_ratio.x)
                if (a[i][j] - last.nr == get_ratio.nr)
                {
                    lenght++;
                    last.y = j;
                    last.x = i;
                    last.nr = a[i][j];
                    cout << a[i][j] << endl;
                }
        }

    return lenght;
}

int maxLenght(int n, int m, int a[NMax][NMax]){
    int max=0;
    coord start;

    for(int height=1;height<n;height++){
        for(int width=1;width<m;width++){
            start.x = height;
            start.y = width;
            start.nr = a[start.x][start.y];
            for(int i=1;i<=n;i++){
                if(i==start.x) i++;
                for(int j=1;j<=m;j++){
                    if(j==start.y) j++;
                    int lenght=0;
                    if(a[i][j]!=start.nr){
                        cout << "NEW LENGHT AT: " << i << ' ' << j << endl;
                        lenght = getLenght(n,m,a,start.x,start.y,i,j);
                    }
                    if(lenght>max)
                        max = lenght;
                }
            }
        }
    }
    return max;
}

int main()
{
    int n, m, a[NMax][NMax], i1, i2, j1, j2;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    f >> i1 >> j1;
    f >> i2 >> j2;
    int lenght = maxLenght(n,m,a);
    cout << "The maximum lenght is " << lenght << endl;
    return 0;
}