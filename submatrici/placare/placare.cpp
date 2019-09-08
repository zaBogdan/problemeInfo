#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 400;
int n,m,a[NMax][NMax], v[NMax][NMax];

void read();
void write_coloana(int lenght,int x,int y){
    lenght = -lenght;
    for(int i=x;i<x+lenght;i++)
        a[i][y] = lenght;
}
void write_linie(int lenght,int x,int y){
    for(int i=y;i<y+lenght;i++)
        a[x][i] = lenght;

}

int main(){
    read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}


void read(){
    ifstream f("placare.in");
    f >> n >> m;
    int val;
    int x=1,y=1,offset_y=0;
    while(f >> val){
        if(val<0){
            write_coloana(val,x,y);
            y++;
            offset_y++;
        }else{
            write_linie(val, x,y);
            y+=val;
        }
        if(y>m)
            x++,y=1+offset_y;
    }
    f.close();
}