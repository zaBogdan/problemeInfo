#include <iostream>
#include <fstream>
using namespace std;
ofstream g("binar.out");
const long int NMax = 10000000;

void read(int &c,int &n,int v[NMax]);
int to_binary(int n);
void highNr(int n,int v[NMax]){
    int maxim = 0,maxim_nr = 0;
    for(int i=1;i<=n;i++){
        int ones = to_binary(v[i]);
        if(maxim < ones){
            maxim_nr = v[i];
            maxim = ones;
        }else if(maxim == ones)
            if(maxim_nr < v[i]){
                maxim_nr = v[i];
            } 
    }
    // cout << "number: " << maxim_nr << endl;
    g << maxim_nr;
    g.close();
}
void sequence(int n,int v[NMax]){
    int init_poz = 1, lenght = 1;
    int first = to_binary(v[1]);
    int mlenght=0, mpoz=1; 

    for(int i=2;i<=n;i++){
        int ones = to_binary(v[i]);
        if(ones == first){
            lenght++;
        }else{
            if(mlenght<lenght){
                mlenght = lenght;
                mpoz = init_poz;
            }   
            first = ones;
            init_poz = i;
            lenght = 1;
        }
    }
    if(mlenght<lenght){
        mlenght = lenght;
        mpoz = init_poz;
    }   

    // cout << mlenght <<  ' ' << mpoz << endl;
    g << mlenght <<  ' ' << mpoz << endl;
    g.close();
}


int main(){
    int c,n,v[NMax];
    read(c,n,v);
    cout << NMax << endl;
    // if(c==1) highNr(n,v);
    // else sequence(n,v);
    return 0;
}

void read(int &c,int &n,int v[NMax]){
    ifstream f("binar.in");
    f >> c >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f.close();
}
int to_binary(int n){
    int nr=0;
    while(n){
        if(n%2==1) nr++; 
        n/=2;

    }
    return nr;
}