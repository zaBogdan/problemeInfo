#include <iostream>
#include <fstream>
#include <cstring>
struct {int val, before=0, after=0,subtract=0,add=0;} val[1000];
using namespace std;
int s;
char expr[1000];

void remove_spaces(char c[1000]);
void give_values(char c[1000]);
void calculat_expr(char c[1000]){
    int i=0;
    if(val[c[i]].before==1){
        if(val[c[i]].add) val[c[i]].val++;
        if(val[c[i]].subtract) val[c[i]].val--;
    }
    s = val[c[i]].val;
    if(val[c[i]].after==1){
        if(val[c[i]].add) val[c[i]].val++;
        if(val[c[i]].subtract) val[c[i]].val--;
    }
    for(int i=1;i<strlen(c);i++){
        if(strchr("+-",c[i])){
             if(val[c[i+1]].before==1){
                if(val[c[i+1]].add) val[c[i+1]].val++;
                if(val[c[i+1]].subtract) val[c[i+1]].val--;
            }
            if(c[i]=='-') s -= val[c[i+1]].val;
            else if(c[i]=='+') s += val[c[i+1]].val;
            if(val[c[i+1]].after==1){
                if(val[c[i+1]].add) val[c[i+1]].val++;
                if(val[c[i+1]].subtract) val[c[i+1]].val--;
            }
        }
    }
}


int main(){
    ifstream f("eval.in");
    char c[1000];
    f.getline(c,1000);
    f.close();
    remove_spaces(c);
    give_values(expr);
    // cout << expr << endl;
    calculat_expr(expr);
    ofstream g("eval.out");
    g << s << endl;
    for(int i=0;i<=30;i++)
        if(val['a'+i].val){
            int e = 'a'+i;
            g << val[e].val<<endl;
        }
    g.close();
    return 0;
}
void remove_spaces(char c[1000]){
    char *p;
    p = strtok(c," ");
    while(p){
        strcat(expr,p);
        p = strtok(NULL," ");
    }
}
void give_values(char c[1000]){
    char s[1000] = "";
    strcpy(s,c);
    int mark = 0,v[1000];
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='+' && c[i+1]=='+'){ //doua plusuri consecutive.
            if(c[i-1]>='a' && c[i-1]<='z'){ //daca se afla in fata caracterului
                val[c[i-1]].after = 1;
                val[c[i-1]].add = 1;
            }
            else if(c[i+2]>='a' && c[i+2]<='z'){ //respectiv dupa
                val[c[i+2]].before = 1;
                val[c[i+2]].add = 1;                
            }
            v[++mark] = i;
            // strcpy(c+i,c+i+2);
        }
        if(c[i]=='-' && c[i-1]=='-'){//respectiv doua minusuri consecutive.
            if(c[i-1]>='a' && c[i-1]<='z'){
                val[c[i-1]].after = 1;
                val[c[i-1]].subtract = 1;
            }
            else if(c[i+2]>='a' && c[i+2]<='z'){
                val[c[i+2]].before = 1;
                val[c[i+2]].subtract = 1;
            }
            // strcpy(c+i,c+i+2);
            v[++mark] = i;
        }
        if(c[i]>='a' && c[i]<='z'){
            if(!val[c[i]].val)
                val[c[i]].val = c[i]-'a'+1;
        }
    }
    for(int i=1;i<=mark;i++){
        strcpy(c+v[i],c+v[i]+2);
        for(int j=i+1;j<=mark;j++)
            v[j]-=2;
    }

}