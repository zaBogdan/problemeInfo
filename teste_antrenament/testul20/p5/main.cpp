#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("file.in");

int main(){
    char text[101];
    f.getline(text,101);
    int len=strlen(text);
    for(int i=0;i<strlen(text);i++){
        if(text[i]==','){
            int k=i+1;
            while(text[k]>='0' && text[k]<='9')
                k++;
            char aux[101];
            strcpy(aux, text+k);
            strcpy(text+i,aux);
            i--;
        }
    }
    cout << text;
    cout << endl;
    return 0;
}