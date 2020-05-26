#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("file.in");

int main(){
    const char vocale[] = "aeiou";
    char text[100]="",*p;
    f.getline(text,100);
    p = strtok(text, " ");
    while(p){
        bool ok = true;
        if(strchr(vocale, p[0]) || strchr(vocale, p[strlen(p)-1]))
            ok = false;
        for(int i=1;i<strlen(p)-2 && ok;i++)
            if(!strchr(vocale,p[i]))
                ok = false;
        if(ok)
            cout << p << endl;

        p = strtok(NULL, " ");
    }
    cout << endl;   
    return 0;
}   