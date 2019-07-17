#include <iostream>
using namespace std;
unsigned long long n,b1,b2,v[10];

int main()
{
    cin >> n >> b1 >> b2;
    int p=1,nd=0;
    while(n){
        nd = nd + (n%10)*p;
        p*=b1;
        n/=10;
    }
    int nr=0;
    while(nd){
        v[++nr]=nd%b2;
        nd/=b2;
    }
    for(int i=nr;i>0;i--)
        cout << v[i];
    return 0;
}
