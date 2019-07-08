#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
struct coord{bool is_pangram, is_perfect;};
int poz,pang,perf_pang;
char a[120][255];

void read();
coord is_pangram(char s[255]);

int main(){
    read();
    
    bool sortat;
    do{
        sortat=true;
        for(int i=1;i<poz;i++)
            if(strcmp(a[i],a[i+1])>0){
                swap(a[i],a[i+1]);
                sortat=false;
            }
    }while(!sortat);
    ofstream g("fraze.out");
    g << pang << ' ' << perf_pang << endl;
    for(int i=1;i<=poz;i++)
        g << a[i] << endl;
    g.close();
    return 0;
}

void read(){
    ifstream f("fraze.in");
    char c[255];
    while(f.getline(c,256)){
        coord info = is_pangram(c);
        if(info.is_pangram){
            pang++;
            strcpy(a[++poz],c);
            if(info.is_perfect)
                perf_pang++;
        }
    }
    f.close();
}
coord is_pangram(char s[255]){
    int f[100];
    memset(f, 0,sizeof(f));
    for(int i=0;i<strlen(s);i++){
        char c = tolower(s[i]);
        f[c-'a']++;
    }
    int lenght = 'z'-'a';
    coord val;
    bool ok = true,ok2 = true;
    for(int i=0;i<=lenght;i++){
        if(f[i]>1)
            ok2 = false;
        if(!f[i])
            ok = false;
    }
    val.is_pangram = ok;
    val.is_perfect = ok2;
    return val;
}