#include <iostream>
using namespace std;
unsigned long long nr=1,minim=2000000000;
int n,divizori,divs,v[300];
bool first=false;
int prime[9]={0,2, 3, 5, 7, 11, 13, 17, 19};

int nr_div(int n);
void afiseaza(){
    if(nr<minim)
        minim = nr;
}
bool valid(int k){
    if(k>divizori)
        return 0;
    nr = 1;
    //construiesc numarul
    for(int i=1;i<=k;i++)
        nr = nr*v[i];
    //mai mic decat 2 milioane
    if(nr>minim)
        return 0;
    //trebuie sa fie numar impar
    if(nr%2==0)
        return 0;
    //trebuie sa aiba acelasi numar de divizori
    divs = nr_div(nr);
    if(divs<=divizori){
        return 1;
    }
    return 0;
}
void bkt(int k){
    if(divs==divizori) afiseaza();
    else
        for(int i=1;i<=8;i++){
            v[k]=prime[i];
            if(valid(k)) bkt(k+1);
        }
}

int main(){
    cin >> n;
    divizori = nr_div(n);
    bkt(1);
    cout << minim;
    return 0;
}
int nr_div(int n){
    int i=0,d=2;
    while(n>1){
        if(d*d==n)
            i++,n=1;
        else if(n%d==0)
            i+=2;
        d++;
        if(d*d>n)
            n=1;
    }
    return i+2;
}