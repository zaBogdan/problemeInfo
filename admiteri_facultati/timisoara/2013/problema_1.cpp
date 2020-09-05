#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("text.in");


void majuscule(char t[255]){
    char *p;
    p = strtok(t, " ");
    while(p){
        p[0]=toupper(p[0]);
        cout << p << endl;
        p=strtok(NULL, " ");
    }
}
int nr_cuv(char t[255]){
    char *p;
    int k=0;
    p = strtok(t, " ");
    while(p){
        if(strlen(p)>2){
            k++;
        }
        p=strtok(NULL, " ");
    }
    return k;
}

int spaces(char t[255]){
    int k=0;
    for(int i=0;i<strlen(t);i++)
        if(t[i]==' ') k++;
    return k;

}

int main(){
    char cs[255],s[255];
    cin.getline(s,255);
    strcpy(cs,s);
    cout << spaces(s) << ' ' << nr_cuv(cs) <<  endl;
    majuscule(s);
}