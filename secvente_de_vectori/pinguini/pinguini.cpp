#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 10001;
ofstream g("pinguini.out");

void read(int &p,int &n, int v[NMax]);
void intervale(int n, int v[NMax]){
    bool sequence = false;
    int interval = 0;
    for(int i=1;i<=n;i++){
        if(v[i]==2 && !sequence){
            interval++;
            sequence = true;
        }
        if(v[i]==1)
            sequence = false;
    }
    // cout << interval << endl;
    g << interval;
}

void lungime_maxima(int n, int v[NMax]){
    int maximal = 0,lungime =0;
    bool sequence = false;
    for(int i=1;i<=n;i++){
        if(v[i]==2){
            lungime++;
        }
        if(v[i]==1){
            if(maximal < lungime){
                maximal = lungime;
            }
            lungime = 0;
        }
    }
    if(maximal < lungime){
        maximal = lungime;
    }
    // cout << maximal << endl;
    g << maximal;
}

int main(){
    int p, n, v[NMax];
    read(p,n,v);
    if(p==2)
        intervale(n,v);
    if(p==3)
        lungime_maxima(n,v);

    return 0;
}


void read(int &p,int &n, int v[NMax]){
    ifstream f("pinguini.in");
    int pinguini=0;
    f >> p;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> v[i];
        if(v[i]==2)
            pinguini++;
    }

    if(p==1)
        g << pinguini;
        // cout << pinguini << endl;

    f.close();
}