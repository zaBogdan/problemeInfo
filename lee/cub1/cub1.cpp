#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 105;
struct initi{int a[NMax][NMax];}v[NMax];
int dk[] = {1,-1,0,0,0,0};
int dx[] = {0,0,1,0,-1,0};
int dy[] = {0,0,0,1,0,-1};
int t,n,fr[7];

void read();
bool valid(int x,int y,int k){
    if(x<1 || y<1 || k<1)
        return 0;
    if(x>n || y>n || k>n)
        return 0;
    return 1;
}
void to_binary(int nr,int fr[]);
int is_access(int k,int x,int y,int fr[]){
    int nr=0;
    for(int i=0;i<6;i++)
        if(fr[i]){
            int newX = x+dx[i];
            int newY = y+dy[i];
            int newK = k+dk[i];
            cout << "Valoarea: "<< i << endl;
            cout << "Sectorul: " <<dk[i] << ' ' << dx[i] << ' ' << dy[i] << endl;
            cout << "Coordonatele: "<< newK << ' ' << newX << ' ' << newY << endl;
            if(valid(newX,newY,newK)){
                nr++;
                // cout << x << ' ' << y << ' ' << k << endl;
            }
            cout << endl;
        }


    return nr;
}

int main(){
    read();
    to_binary(57,fr);
    cout << is_access(1,2,1,fr);
    return 0;
}

void read(){
    ifstream f("cub1.in");
    f >> t >> n;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f >> v[k].a[i][j];
    }
    f.close();
}
void to_binary(int nr,int fr[]){
    int i=6;
    while(nr){
        fr[--i] = nr%2;
        nr/=2;
    }
}