#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("bac.txt");
// ofstream g("bac.out");
char s[201],*p,vocale[]="aeiouAEIOU";
int nrcuv;

int main(){
    f.get(s,101);
    p=strtok(s, " ");
    while(p)
    {
        int nrvoc=0;
        for(int i=0; i<strlen(p); i++)
            if(strchr(vocale,p[i]))
                nrvoc++;
    
        if(nrvoc==strlen(p)-nrvoc)
            nrcuv++;
        p=strtok(NULL," ");
    }
    cout << endl;
        cout<<nrcuv;
    return 0;
}