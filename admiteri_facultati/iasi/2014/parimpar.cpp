#include <iostream>
#include <fstream>
using namespace std;
ifstream f("rmatrix.in");
const int NMax = 20;
int a[NMax][NMax],b[NMax][NMax];


void multiply_matrix(int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            b[i][j]=0;
            for(int k=1;k<=n;k++)
                b[i][j]+=a[i][k]*a[k][j];
        }
}

bool check_if_parimpar(int n){
    int parity = (b[1][1]%2==1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(b[i][j]%2!=parity)
                return 0;
    return 1;

}

int main(){
    int n;
    f >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f >> a[i][j];
    multiply_matrix(n);
    cout << check_if_parimpar(n) << endl;
    return 0;
}