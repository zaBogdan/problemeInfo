#include <iostream>
using namespace std;


void aranjare(double a[100], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]){
                double aux = a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}

int main(){
    double vector[] = {12,-7.5,6.5,-3,-8,7.5};
    aranjare(vector, 6);
    for(int i=0;i<6;i++)
        cout << vector[i] << ' ';
    cout << endl; 
    return 0;
}