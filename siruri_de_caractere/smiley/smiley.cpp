#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int nr;
char s[255];

int check_smiley(char s[255]){
    int nr = 0,i=0;
    while(i<strlen(s)){
        if(strchr(":;>8", s[i])){
            i++;
            while(s[i]=='-') i++;
            if(s[i] && strchr("()[]DPOX3",s[i])) nr++;
        }
        else i++;
    }
    return nr;
}

int main(){
    ifstream f("smiley.in");
    while(f.getline(s,255))
        nr+= check_smiley(s);
    f.close();
    ofstream g("smiley.out");
    g << nr;
    g.close();
    return 0;
}
