#include <iostream>
using namespace std;
const int NMax=10;

//punctul c)
int sumaDiag(int a[NMax][NMax], int n){
    int s=0;
    for(int i = n/2;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i>j && i+j>n+1)
                s+=a[i][j];
    return s;
}

//punctul d)
void linieMax(int a[NMax][NMax], int n){
    for(int i=1;i<=n;i++){
        int maxi = -100000000;
        for(int j=1;j<=n;j++)
            if(maxi<a[i][j])
                maxi = a[i][j];
        cout << maxi << ' ';
    }
    cout << endl;
}

//puncutl e)
void interschimbare(int a[NMax][NMax],int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        //luam toate elemente care sunt sub ambele diagonale 
            if(i>j && i+j>n+1){
                //cand am gasit elementul il mutam in partea opusa a matricii
                swap(a[i][j],a[n-i+1][j]);
            }

cout << endl << endl << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
int main(){
    /*
        Punctul a)
            (i) i=j
            (ii) i+j-1=n
            (iii) i> j
            (iv) i+j>n+1 
     */
    int n,a[NMax][NMax];
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];

    // linieMax(a,n);
    interschimbare(a,n);
    return 0;
}