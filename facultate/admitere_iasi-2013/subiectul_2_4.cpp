#include <iostream>
#include <cstring>
using namespace std;
char first[256];

int main()
{
    char s[256];
    cin.get(s, 256);
    int n = strlen(s);
    //este posibila mereu impartirea la 4 intrucat n este par iar sirul are lungimea 2n

    //building the word
    int row = n / 4;
    for (int i = 0; i < row; i++)
    {
        first[i] = s[row * i + 3-i];
        first[i+row] = s[row * i +i]; 
    }
    first[n] = '\n';
    
    //printing the word
    cout << first << endl;
    return 0;
}