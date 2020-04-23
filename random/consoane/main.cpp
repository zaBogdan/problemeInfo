#include <iostream>
#include <cstring>
using namespace std;
char delimiters[] = " ,.!/";
char vocale[] = "aeiouAEIOU";

int main(){
    bool h = false;
    char txt[255];
    cin.get(txt,255);
    char *p = strtok(txt, delimiters);
    while(p){
        int voc=0;
        for(int i=0;i<strlen(p);i++)
            if(strchr(vocale, p[i]))
                voc++;
        if(voc < strlen(p) - voc){
            cout << p << endl;
            h = true;
        }
        p = strtok(NULL, delimiters);
    }
    if(!h)
        cout << "nu exista";
    return 0;
}