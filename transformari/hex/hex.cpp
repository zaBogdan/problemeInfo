#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char val[][5] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char c[10007];

int main(){
    ifstream f("hex.in");
    f.getline(c,10007);
    f.close();
    ofstream g("hex.out");
    int lenght = strlen(c);
    int offset = lenght%4;
    if(offset!=0){
        char aux[5]="0000";
        for(int i=0;i<offset;i++)
            aux[i+(4-offset)] = c[i];
        for(int j=0;j<16;j++){
            if(strcmp(val[j],aux)==0){
                if(j<10)
                    g << j;
                else{
                    char litera = 'A'+j%10;
                    g << (char) litera;
                }
                j=17;
            }
        }
    }
    for(int i=offset;i<lenght;i+=4){
        char aux[5]="";
        for(int j=i;j<=i+3;j++){
            aux[j-i] = c[j];
        }
        for(int j=0;j<16;j++){
            if(strcmp(val[j],aux)==0){
                if(j<10)
                    g << j;
                else{
                    char litera = 'A'+j%10;
                    g << (char) litera;
                }
                j=17;
            }
        }
    }
    g.close();


    return 0;
}
