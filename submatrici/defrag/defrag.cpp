#include <iostream>
#include <fstream>
using namespace std;
ofstream g("defrag.out");
const int NMax = 1001;
int p,pist,sect,clu,a[NMax][NMax],frecv[NMax];

void read();
void first();
int calculate(int linia,int lungime){
    int minim = sect*2;
    for(int i=1;i<=sect*2-lungime+1;i++){
        int nr=0;
        for(int j=i;j<i+lungime;j++){
            if(!a[linia][j])
                nr++;
        }
        if(nr<minim)
            minim=nr;
    }
    return minim;
}

void second(){
    for(int i=1;i<=pist;i++){
        if(frecv[i]){
            int lungime = frecv[i];
            int number = calculate(i,lungime);
            frecv[i]=number;
        }
    }
    for(int i=1;i<=pist;i++)
        g << frecv[i] << ' ';
}

int main(){
    read();
    if(p==1) first();
    else second();
    // for(int i=1;i<=pist;i++){
    //     for(int j=1;j<=sect*2;j++)
    //         cout << a[i][j] << ' ';
    //     cout << endl;
    // }
    g.close();
    return 0;
}

void read(){
    ifstream f("defrag.in");
    f >> p;
    f >> pist >> sect;
    f >> clu;
    for(int i=1;i<=clu;i++){
        int x,y;
        f >> x >> y;
        a[x][y]=a[x][y+sect]=1;
        frecv[x]++;
    }
}
void first(){
    int nr=0;
    for(int i=1;i<=pist;i++)
        if(!frecv[i])
            nr++;
    g << nr;
}