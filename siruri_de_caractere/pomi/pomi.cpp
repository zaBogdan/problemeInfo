#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 85;
short a[NMax],b[NMax],k;

// void idee(){
//     int start = a+k-a%k;
//     int finish = b-b%k;
//     int nr = (finish-start)/k+1;
// }
void read();
void transform(short v[NMax],char c[NMax]);
void subtract(short v[NMax],int k){

}
int calc_mod(short v[NMax], int k){

}

int main(){
    read();
    
    return 0;
}

void read(){
    ifstream f("pomi.in");
    char a1[NMax],b1[NMax];
    f.getline(a1,NMax);
    f.getline(b1,NMax);
    f >> k;
    transform(a,a1);
    transform(b,b1);
    f.close();
}
void transform(short v[NMax],char c[NMax]){
    int lenght = strlen(c);
    v[0]=lenght;
    while(lenght){
        v[lenght]= c[lenght-1]-'0';
        lenght--;
    }

}