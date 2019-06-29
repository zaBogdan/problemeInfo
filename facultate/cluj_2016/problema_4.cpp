#include <iostream>
using namespace std;
//CARE E MAI EFICIENTA?


int prodMax2(int n, int x[],int &a,int &b,int &c){
    //elimin si cazurile cu 0
    int prod=1,maxy=-1;
    for(int i=1;i<n-1;i++)
        if(x[i])
        for(int j=i+1;j<n;j++)
            if(x[j])
            for(int k=j+1;k<=n;k++)
                if(x[k]){
                prod = x[i]*x[j]*x[k];
                if(maxy<prod){
                    maxy=prod;
                    a=x[i],b=x[j],c=x[k];
                }
            }
}

int prodMax(int n, int x[],int &a,int &b,int &c){
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(x[i]>x[j])
                swap(x[i],x[j]);
    int prodA=1,prodB=1;
    for(int i=0;i<3;i++){
        prodA*=x[1+i];
        prodB*=x[n-i];
    }
    if(prodA>prodB){
        a=x[1],b=x[2],c=x[3];
    }else
    {
        a=x[n-2],b=x[n-1],c=x[n];
    }
    

}

int main(){
    int a,b,c;
    int n;
    n=10;
    int x[]={0,3,-5,0,5,2,-1,0,1,6,8};
    prodMax2(n,x,a,b,c);
    cout << a << ' ' << b << ' '<< c << endl;
    return 0;
}