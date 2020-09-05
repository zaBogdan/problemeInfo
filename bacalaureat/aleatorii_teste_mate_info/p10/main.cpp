#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("tactu.in");

int main(){
    char cuvinte[255],zeu[255]="";
    f.getline(cuvinte, 255);
    char *p;
    p = strtok(cuvinte, " ");
    while(p){
        int len = strlen(p);
        if(len%2==0){
            strcat(zeu, p + len/2);
            strncat(zeu, p, len/2);
        }else
            strcat(zeu,  p);
        strcat(zeu, " ");
        p= strtok(NULL, " ");
    }
    cout << zeu << endl;
    return 0;
}