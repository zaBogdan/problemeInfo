#include <iostream>
using namespace std;

//punctul a)
void shift(int n,int x[100]){
    //salvez primul element intr-un parametru auxiliar
    int aux = x[0];
    //shiftez tot vectorul
    for(int i=1;i<n;i++)
        x[i-1]=x[i];
    //pun primul element pe ultimul loc
    x[n-1]=aux;
}

int main(){
    int n;
    cin >> n;
    int x[100];
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<n-1;i++)
        shift(n,x);

    for(int i=0;i<n;i++)
        cout << x[i] << ' ';
    cout << endl;
    return 0;
}