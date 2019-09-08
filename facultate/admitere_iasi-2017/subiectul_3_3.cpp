#include <iostream>
#include <fstream>
using namespace std;
ifstream f("intrerupator.in");
const int NMax = 100;

void check_matrix(int n, int m, bool a[NMax][NMax], int i, int j)
{
    int dx[] = {0, -1, 0, -1};
    int dy[] = {0, 0, -1, -1};
    for (int k = 0; k < 4; k++)
        a[i + dx[k]][j + dy[k]] = a[i + dx[k]][j + dy[k]] == 0 ? 1 : 0;
}
bool light_status(int n, int m, bool a[NMax][NMax])
{
    //not finished. 
    int dx[] = {0, -1, 0, -1};
    int dy[] = {0, 0, -1, -1};
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
        {
            bool wrong = false;
            check_matrix(n, m, a, i, j);
            for (int k = 0; k < 4 && !wrong; k++)
                wrong = (a[i + dx[k]][j + dy[k]] != 0);
            if (wrong)
                check_matrix(n, m, a, i, j);
            else cout << i << ' ' << j << endl;
        }
    return 1;
}

int main()
{
    int n, m;
    bool a[NMax][NMax];
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    light_status(n,m,a);
}