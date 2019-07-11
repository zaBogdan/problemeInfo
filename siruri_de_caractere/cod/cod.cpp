#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int poz = 1;
char s[100][255];

bool is_ok(char c[256],int st,int fn,int &nr);
void parse(char c[256],int &poz);
void reverse(char s[256]){
    char c;
    for(int i=0;i<strlen(s)/2;i++){
        c = s[i];
        s[i] = s[strlen(s)-i-1];
        s[strlen(s)-i-1] = c;
    }
    // cout << s << endl;
}
int main(){
    ifstream f("cod.in");
    ofstream g("cod.out");
    char c[256];
    while(f.getline(c,255)){
        parse(c,poz);
        for(int i=1;i<=poz;i++){
            reverse(s[poz]);
            g << s[i];
        }
        g << endl;
    }
    f.close();
    g.close();
    return 0;
}

bool is_ok(char c[256],int st,int fn,int &nr){
    int nd=0,p=1;
    while(st<=fn){
        nd = nd + (c[st]-'0')*p;
        p*=10;
        st++;
    }
    nr = nd;
    if(nr == '.' || nd == ' ')
        return 1;
    
    if(nr>='a' && nr<='z')
        return 1;
    if(nr>='A' && nr<='Z')
        return 1;
    return 0;
}
void parse(char c[256],int &poz){
    int element = 0;
    poz=1;
    memset(s,0,sizeof(s));
    for(int i=0;i<strlen(c);i++){
        int nr=0;
        if(is_ok(c,i,i+1,nr)){
            s[poz][element++] = (char) nr;
            i = i+1;
        }else if(is_ok(c,i,i+2,nr)){
            s[poz][element++] = (char) nr;
            i = i+2;
        }
        
        if(nr == '.' || nr ==' '){
            s[poz][--element] = '\0';
            reverse(s[poz]);
            element = 0;
            s[++poz][0]= (char) nr;
            s[++poz][1]= '\0';
            poz++;            
        }
    }
}