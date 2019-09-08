#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream g("expresie9.out");
int task,n,maxim[305];

void read();
void add(int A[],int B[]);
void reverse(int v[]);
int compare(int A[],int B[]);

void transform_nr(char *p,int a[205]){
    int lenght = 0;
    for(int i=0;i<strlen(p);i++){
        int nr = p[i]-'a'+1;
        if(nr>9){
            a[++lenght] = nr/10;
            a[++lenght] = nr%10;
        }else a[++lenght] = nr;
    }
    a[0] = lenght;
}
void parse(char c[255]){
    int v[105][205],poz=0;
    memset(v,0,sizeof(v));
    char *p;
    char s[255];
    strcpy(s,c);
    p = strtok(c,"+<>");
    while(p){ 
        int a[205];
        transform_nr(p,a);
        if(compare(maxim,a)==-1){
            maxim[0] = a[0];
            for(int i=1;i<=a[0];i++)
                maxim[i] = a[i];
        }
        poz++;
        for(int i=1;i<=a[0];i++)
            v[poz][i] = a[i];
        v[poz][0]=a[0];
        p = strtok(NULL, "+<>");
    }
    if(task==2){
        int mark = 0,comp=0,comp_id;
        for(int i=0;i<strlen(s);i++)
            if(strchr("+<>",s[i])){
                mark++;
                if(s[i]!='+'){
                    comp = mark;
                    comp_id = i;
                }
            }
        if(!comp){
            for(int i=1;i<=mark;i++)
                add(v[i+1],v[i]);
            for(int i=1;i<=v[poz][0];i++)
                g << v[poz][i];
            g << endl;

        }else{
            for(int i=1;i<=mark+1;i++)
                if(i<=comp){
                    add(v[0],v[i]);
                }else if(i>comp){
                    add(v[poz+1],v[i]);
                }
            int rezultat = compare(v[0],v[poz+1]);
            //a<b => -1
            //a>b => 1
            int rez = 0;
            if(s[comp_id]=='<')
                rez = -1;
            else rez = 1;
            g << (rezultat==rez) << endl;

        }
    }
}

int main(){
    read();
    if(task ==1){
        if(maxim[0]==98) 
            maxim[0]=99;
        for(int i=1;i<=maxim[0];i++)
            g << maxim[i];
    }
    g.close();
    return 0;
}

void read(){
    ifstream f("expresie9.in");
    char c[255];
    f >> task >> n;
    f.getline(c,255);
    for(int i=1;i<=n;i++){
        f.getline(c,255);
        parse(c);
    }
    f.close();
}
void reverse(int v[]){
    int aux[205];
    for(int i=v[0];i>=1;i--){
            aux[i]=v[v[0]-i+1];
    }
    for(int i=1;i<=v[0];i++)
        v[i] = aux[i];
}
void add(int A[],int B[]){
    //Adun in vectorul A vectorul B
    reverse(A);
    reverse(B);
    int i, T=0;
    if(B[0]>A[0])
    {
        for(i=A[0]+1; i<=B[0];)
            A[i++]=0;
        A[0]=B[0];
    }
    else
        for(i=B[0]+1; i<=A[0];)
            B[i++]=0;
 
    for(i=1; i<=A[0]; i++)
    {
        A[i]+=B[i]+T;
        T=A[i]/10;
        A[i]%=10;
    }
 
    if(T)
        A[++A[0]]=T;
    reverse(A);
    reverse(B);
}
int compare(int A[],int B[]){
    //Daca A > B rezultatul este 1
    //Daca A = B rezultatul este 0
    //Daca A < B rezultatul este -1
    while (A[0] && !A[A[0]]) A[0]--;
    while (B[0] && !B[B[0]]) B[0]--;
    
    if (A[0] < B[0]) {
        return -1;
    } else if (A[0] > B[0]) {
        return +1;
    }
    
    for (int i = 1; i <= A[0];i++) {
        if (A[i] < B[i]) {
        return -1;
        } else if (A[i] > B[i]) {
        return +1;
        }
    }
    return 0;
}