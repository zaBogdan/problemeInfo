#include <iostream>
#include <fstream>
using namespace std;
ifstream f1("nr1.txt");
ifstream f2("nr2.txt");
int v1[101],v2[101],m,n;

int binary(int nr,int upper,int v[101]){
    int ls=1,ld=upper;
    while(ls<=ld){
        int mij = (ls+ld)/2;
        if(v[mij]==nr)
            return mij;
        else{
            if(nr<v[mij])
                ld=mij-1;
            else ls=mij+1;
        }
    }
    return 0;
}
int main(){
    int x=1;
    while(f1 >> v1[x++])
        n++;
    x=1;
    while(f2 >> v2[x++])
        m++;
    int i=1,j=1;

    while(i<=n || j<=m){
        while((v1[i]<=v2[j] || j>m) && i<=n){
            if(v1[i]%5==0 && !binary(v1[i],m,v2))
                cout << v1[i] << ' ';
            i++;
        }
        while((v2[j]<=v1[i] || i>n) && j<=m){
            if(v2[j]%5==0 && !binary(v2[j],n,v1))
                cout << v2[j] << ' ';
            j++;
        }
    }

    cout << endl; //development purpose.
    return 0;
} 