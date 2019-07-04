#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 400;
int n,m,a[NMax][NMax], v[NMax][];

void read();
int transform_int(char *p);
void insert(int i,int poz, char s[]){
    char *p;
    p = strtok(s, " ");
    while(p){
        int nr = transform_int(p);
        v[i] = nr;
        p = strtok(NULL, " ");
    }
}


int main(){
    read();
    return 0;
}


void read(){
    char x[300];
    int poz=0;
    ifstream f("placare.in");
    f >> n >> m;
    char s[NMax];
    f.getline(s,NMax);
    for(int i=1;i<=n;i++){
        f.getline(s,NMax);
        poz++;
        insert(i,poz,s);
    }
    f.close();
}
int transform_int(char *p){
    int nd=0,pr=1;
    int poz = 0;
    if(p[0]=='-')
        poz = 1;
    for(int i=poz;i<strlen(p);i++){
        int n = p[i]-'0';
        nd = nd*10 + n;
    }
    if(poz)
        return -nd;
    return nd;
}