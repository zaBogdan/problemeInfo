#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream g("careu.out");
const int NMax = 55;
int n,maxim,poz,task;
char palindroame[1000][NMax],sortare[1000][NMax],a[NMax][NMax];

void read();
bool is_palindrom(char *p);
void parse(char c[NMax]);

int main(){
    read();
    for(int i=1;i<=n;i++){
        char c[NMax]="";
        for(int j=1;j<=n;j++){
            c[j-1]=a[j][i-1];
        }
        c[n]='\0';
        parse(c);
    }
    if(task==1){
        int poz2=0;    
        for(int i=1;i<=poz;i++)
            if(strlen(palindroame[i])==maxim)
                strcpy(sortare[++poz2],palindroame[i]);

        bool sortat;
        do{
            sortat= true;
            for(int i=1;i<poz2;i++)
                if(strcmp(sortare[i],sortare[i+1])>0){
                    sortat=false;
                    swap(sortare[i],sortare[i+1]);
                }
        }while(!sortat);
        int elemente = poz2;
        for(int i=1;i<poz2;i++)
            if(strcmp(sortare[i],sortare[i+1])==0)
                elemente--;
        g << elemente << endl;
        for(int i=1;i<=poz2;i++)
            if(strcmp(sortare[i],sortare[i+1]))
                g << sortare[i] << endl;
    }
    else{
        int f[40];
        memset(f,0,sizeof(f));
        for(int i=1;i<=poz;i++){
            if(strlen(palindroame[i])==maxim){
                for(int j=0;j<strlen(palindroame[i]);j++)
                    f[palindroame[i][j]-'A']++;
            }
        }
        int s=0;
        for(int i=0;i<=26;i++)
            if(f[i]){
                s+= 'A'+i;
            }
        g << s << endl;
    }

    return 0;
}

void read(){
    ifstream f("careu.in");
    char c[NMax];
    f >> n;
    f.getline(c,NMax);
    for(int i=1;i<=n;i++){
        f.getline(c,NMax);
        strcpy(a[i],c);
        parse(c);
    }
    f >> task;
    f.close();
}
bool is_palindrom(char *p){
    int lenght = strlen(p);
    for(int i=0;i<=lenght/2;i++)
        if(p[i]!=p[lenght-1-i])
            return 0;
    return 1;
}
void parse(char c[NMax]){
    char *p;
    p = strtok(c,".");
    while(p){
        if(is_palindrom(p) && strlen(p)>=2){
            strcpy(palindroame[++poz], p);
            if(maxim<strlen(p))
                maxim =  strlen(p);
        }
        p = strtok(NULL, ".");
    }
}