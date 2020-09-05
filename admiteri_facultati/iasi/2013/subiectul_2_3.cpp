#include <iostream>
using namespace std;
int a[50][50];

int main()
{
    char s[256];
    cin.get(s, 256);
    //este posibila mereu impartirea la 4 intrucat n este par iar sirul are lungimea 2n
    int row = n / 4;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= row; j++)
            a[i][j] = s[n * (i - 1) + j - 1];


    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= row; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}